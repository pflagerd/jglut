SHELL = /bin/bash

directory_containing_this_makefile=$(dir $(realpath $(firstword $(MAKEFILE_LIST))))

export PATH ::= $(directory_containing_this_makefile)bin/:$(realpath $(directory_containing_this_makefile)../)/bin/:$(PATH)

CPPFLAGS=\
	-std=gnu99\
	-O0\
	-g3\
	-m64\
	-Wall\
	-I$(directory_containing_this_makefile)include\
	-I$(directory_containing_this_makefile)jdk1.8.0_72/include\
	-I$(directory_containing_this_makefile)jdk1.8.0_72/include/linux\
	-I$(directory_containing_this_makefile)src

LDFLAGS_LIN=\
	-Wl,--no-as-needed\
	-Wl,--start-group\
	$(directory_containing_this_makefile)lib64/libglut.a -lGLU -lGL -lX11 -lXrandr -lXxf86vm -lXi\
	-Wl,--end-group -Wl,--no-undefined -Wl,--no-allow-shlib-undefined
	
LDFLAGS_WIN=\
	-Wl,--no-as-needed\
	-Wl,--start-group\
	/usr/x86_64-w64-mingw32/sys-root/mingw/lib/libglut.dll.a -lglut -lglu32 -lopengl32\
	-Wl,--end-group

PROCESSES := 8

.PHONY: all
all: jar/jglut.jar

.PHONY: check
check: all
	jdk1.8.0_72/bin/javac -g -parameters -d bin test/org/pflager/*.java test/org/pflager/gl/*.java -cp jar/jglut.jar:`echo jar/*.jar | tr ' ' ':'`
	jdk1.8.0_72/bin/java -jar jar/junit-platform-console-standalone-1.8.1.jar -cp bin --scan-classpath
	#jdk1.8.0_72/bin/java -jar jar/junit-platform-console-standalone-1.8.1.jar -cp bin --select-class org.pflager.AllTests

jar/jglut.jar: bin/libjglut.so bin/libjglut.dll bin/libglut-0.dll
	strip bin/libjglut.so
	/usr/x86_64-w64-mingw32/bin/strip bin/libjglut.dll
	cp src/com/pflager/*.java bin/com/pflager
	jdk1.8.0_72/bin/jar cfm jar/jglut.jar manifest.txt -C bin com -C bin libglut-0.dll -C bin libjglut.dll -C bin libjglut.so
	touch jar/jglut.jar
	
bin/libjglut.so: lib64/libjglut.so | bin/
	cp -f lib64/libjglut.so bin/libjglut.so
	cp -f lib64/libjglut.so src/libjglut.so

bin/libglut-0.dll: src/libglut-0.dll | bin/
	cp -f src/libglut-0.dll bin/libglut-0.dll # we do this because eclipse JDT will attempt to erase bin, rebuild bin and recopy from src
	touch bin/libglut.dll

lib64/libjglut.so: linux-build/.libs/libjglut.so
	cd linux-build; $(MAKE) install
	touch lib64/libjglut.so # this may be unnecessary

bin/libjglut.dll: windows-build/.libs/libjglut.dll | bin/
	cd windows-build; $(MAKE) install
	cp windows-build/.libs/libjglut.dll src/libjglut.dll # we do this because eclipse JDT will attempt to erase bin, rebuild bin and recopy from src
	touch bin/libjglut.dll # this may be unnecessary

# .generatedHeadersAndCompiledJava stands for src/com_pflager_glut.h src/com_pflager_glu.h src/com_pflager_gl.h bin/com
	
linux-build/.libs/libjglut.so: linux-build/Makefile .generatedHeadersAndCompiledJava $(wildcard src/*.c src/*.h)
	cd linux-build; $(MAKE) -j $(PROCESSES) && touch .libs/libjglut.so

windows-build/.libs/libjglut.dll: windows-build/Makefile .generatedHeadersAndCompiledJava $(wildcard src/*.c src/*.h)
	cd windows-build; $(MAKE) -j $(PROCESSES) && touch .libs/libjglut.dll

.generatedHeadersAndCompiledJava: jdk1.8.0_72/bin/javac $(wildcard src/com/pflager/*.java) makefile | bin/
	jdk1.8.0_72/bin/javac -parameters -g -d bin -h src $(wildcard src/com/pflager/*.java) $(wildcard src/net/pflager/*.java)
	touch .generatedHeadersAndCompiledJava

src/net_pflager_gles2_JNI.h: src/net/pflager/gles2.java

src/Java_net_pflager_gles2_JNI.c: src/net/pflager/gles2.java

src/net/pflager/gles2.java: ../OpenGL-Registry/xml/gl.xml
	jdk1.8.0_72/bin/javac -g -parameters -d bin -cp jar/commons-io-2.6.jar $(wildcard ../GenerateGLCode/src/org/pflager/*.java)
	jdk1.8.0_72/jre/bin/java -cp ../GenerateGLCode/bin org.pflager.JavaAndCJniCodeGenerator

jdk1.8.0_72/bin/javac: jdk-8u72-linux-x64.tar.gz
	tar xzf jdk-8u72-linux-x64.tar.gz && touch jdk1.8.0_72/bin/javac

jdk-8u72-linux-x64.tar.gz:
	wget -N --quiet https://github.com/pflagerd/jglut/releases/download/v0.1.4/jdk-8u72-linux-x64.tar.gz
	touch jdk-8u72-linux-x64.tar.gz

linux-build/Makefile: src/configure lib64/libglut.a | linux-build
	cd linux-build; ../src/configure --prefix=$(directory_containing_this_makefile) WIN32= CPPFLAGS="$(CPPFLAGS)" LDFLAGS="$(LDFLAGS_LIN)"

windows-build/Makefile: src/configure | windows-build .mingw64-cross-gcc .mingw64-freeglut-devel
	cd windows-build; ../src/configure --host=x86_64-w64-mingw32 --prefix=$(directory_containing_this_makefile) WIN32=win32-dll CPPFLAGS="$(CPPFLAGS) -DGLUT_DISABLE_ATEXIT_HACK" LDFLAGS="$(LDFLAGS_WIN)"

src/configure: src/configure.ac src/Makefile.am makefile lib64/libglut.a | .autoconf .automake .libtool /usr/lib64/libXrandr.so /usr/lib64/libXxf86vm.so .version
	@printf '\nExecuting target: src/configure\n'
	cd src; autoreconf --force --install 2>/dev/null # the 2>/dev/null is to suppress info that eclipse thinks are errors
	touch src/configure

lib64/libglut.a: freeglut-3.2.1/build/ | .cmake
	cd freeglut-3.2.1/build/; cmake -DCMAKE_INSTALL_PREFIX:PATH=$(directory_containing_this_makefile) ..; make -j $(PROCESSES); make install
	touch lib64/libglut.a
	
freeglut-3.2.1/build/: freeglut-3.2.1/
	mkdir freeglut-3.2.1/build/

freeglut-3.2.1/:
	git clone git@gitlab.pflager.net:jglut/freeglut-3.2.1.git


.version:
	@version=($$(git status | head -1)); if ! head -1 src/configure.ac | grep $${version[2]} > /dev/null; then echo "update configure.ac to $${version[2]}"; exit 1; fi
	touch .version

bin/:
	mkdir bin

linux-build:
	mkdir linux-build

windows-build:
	mkdir windows-build

.autoconf:
	@version=$$(autoconf --version | head -1 | cut -d" " -f 4); if [ "$$version" == "2.69" ]; then echo $$version > .autoconf; else echo "autoconf 2.69 not found or wrong version"; sudo zypper install -y autoconf; fi

.automake:
	@version=$$(automake --version | head -1 | cut -d" " -f 4); if [ "$$version" == "1.15.1" ]; then echo $$version > .automake; else echo "automake 1.15.1 not found or wrong version"; sudo zypper install -y automake; fi

.cmake:
	@version=$$(cmake --version | head -1 | cut -d" " -f 3); if [ "$$version" == "3.22.1" ]; then echo $$version > .cmake; else echo "cmake 3.22.1 not found or wrong version"; exit 1; fi

.gcc:


.libtool:
	@version=$$(libtool --version | head -1 ); if [ "$$version" == "2.4.6" ]; then echo $$version > .libtool; else echo "libtool 2.4.6 not found or wrong version"; sudo zypper install -y libtool; fi

.mingw64-cross-gcc:
	@version=($$(x86_64-w64-mingw32-gcc --version | head -1)); if [ "$${version[3]}" == "9.2.0" ]; then echo $${version[3]} > .mingw64-cross-gcc; else echo "mingw64-cross-gcc 9.2.0 not found or wrong version"; sudo zypper install -y mingw64-cross-gcc; fi


.mingw64-freeglut-devel:
	@version=($$(zypper search -s -i mingw64-freeglut-devel | head -6 | tail -1)); if [ "$${version[6]}" == "2.8.1-lp153.5.10" ]; then echo $${version[6]} > .mingw64-freeglut-devel; else echo "mingw64-freeglut-devel 2.8.1-lp153.5.10 not found or wrong version"; sudo zypper install -y mingw64-freeglut-devel; fi

/usr/lib64/libXxf86vm.so:
	sudo zypper install -y libXxf86vm-devel

/usr/lib64/libXrandr.so:
	sudo zypper install -y libXrandr-devel


.PHONY: clean
clean:
	rm -f .generatedHeadersAndCompiledJava
	rm -f lib/jglut.jar
	rm -rf lib64/
	rm -rf bin/
	rm -f src/com_pflager_gl.h
	rm -f src/com_pflager_glu.h
	rm -f src/com_pflager_glut.h
	rm -f src/net_pflager_gles2.h
	rm -f src/net/pflager/gles2.java
	rm -rf src/autom4te.cache/
	rm -rf src/config/
	rm -rf src/m4/
	rm -f src/Makefile.in
	rm -f src/aclocal.m4
	rm -f src/configure
	rm -f src/libjglut.*
	rm -rf linux-build
	rm -rf windows-build
	rm -rf jdk-8u72-linux-x64.tar.gz
	rm -rf jdk1.8.0_72
	cd freeglut-3.2.1; git clean -dfx
	
