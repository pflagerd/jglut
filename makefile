SHELL = /bin/bash

directory_containing_this_makefile=$(dir $(realpath $(firstword $(MAKEFILE_LIST))))

CPPFLAGS=\
	-std=gnu99\
	-O0\
	-g3\
	-m64\
	-Wall\
	-I$(directory_containing_this_makefile)jdk1.8.0_72/include\
	-I$(directory_containing_this_makefile)jdk1.8.0_72/include/linux\
	-I$(directory_containing_this_makefile)src

LDFLAGS_LIN=\
	-Wl,--no-as-needed\
	-Wl,--start-group\
	-L/usr/lib64 -lglut -lGLU -lGL\
	-Wl,--end-group -Wl,--no-undefined -Wl,--no-allow-shlib-undefined
	
LDFLAGS_WIN=\
	-Wl,--no-as-needed\
	-Wl,--start-group\
	-L/usr/lib64 -lglut -lglu32 -lopengl32\
	-Wl,--end-group

PROCESSES := 16

.PHONY: all
all: jar/jglut.jar

.PHONY: check
check: all
	jdk1.8.0_72/bin/javac -g -d bin test/org/pflager/*.java test/org/pflager/gl/*.java -cp jar/jglut.jar:`echo jar/*.jar | tr ' ' ':'`
	jdk1.8.0_72/bin/java -jar jar/junit-platform-console-standalone-1.8.1.jar -cp bin --scan-classpath
	#jdk1.8.0_72/bin/java -jar jar/junit-platform-console-standalone-1.8.1.jar -cp bin --select-class org.pflager.AllTests

jar/jglut.jar: linux windows
	strip bin/libjglut.so
	/usr/x86_64-w64-mingw32/bin/strip bin/libjglut.dll
	cp src/com/pflager/*.java bin/com/pflager
	jdk1.8.0_72/bin/jar cf jar/jglut.jar -C bin com -C bin libglut-0.dll -C bin libjglut.dll -C bin libjglut.so

.PHONY: linux
linux: bin/libjglut.so

.PHONY: windows
windows: bin/libjglut.dll bin/libglut-0.dll

bin/libjglut.so: lib64/libjglut.so
	cp -f lib64/libjglut.so bin/libjglut.so
	cp -f lib64/libjglut.so src/libjglut.so

src/libjglut.dll: bin/libjglut.dll
	cp -f bin/libjglut.dll src/libjglut.dll

bin/libglut-0.dll: src/libglut-0.dll | bin
	cp -f src/libglut-0.dll bin/libglut-0.dll
	
lib64/libjglut.so: linux-build/.libs/libjglut.so
	cd linux-build; $(MAKE) install
	touch lib64/libjglut.so # this may be unnecessary

bin/libjglut.dll: windows-build/.libs/libjglut.a | bin
	cd windows-build; $(MAKE) install
	touch bin/libjglut.dll # this may be unnecessary

# .generatedHeadersAndCompiledJava stands for src/com_pflager_glut.h src/com_pflager_glu.h src/com_pflager_gl.h bin/com
	
linux-build/.libs/libjglut.so: linux-build/Makefile .generatedHeadersAndCompiledJava src/*.c src/*.h
	cd linux-build; $(MAKE) -j $(PROCESSES) && touch .libs/libjglut.so
	
windows-build/.libs/libjglut.a: windows-build/Makefile .generatedHeadersAndCompiledJava src/*.c src/*.h
	cd windows-build; $(MAKE) -j $(PROCESSES) && touch .libs/libjglut.a	

.generatedHeadersAndCompiledJava: jdk1.8.0_72/bin/javac src/com/pflager/*.java | bin
	jdk1.8.0_72/bin/javac -g -d bin -h src src/com/pflager/*.java
	touch .generatedHeadersAndCompiledJava

jdk1.8.0_72/bin/javac: jdk-8u72-linux-x64.tar.gz
	tar xzf jdk-8u72-linux-x64.tar.gz && touch jdk1.8.0_72/bin/javac

jdk-8u72-linux-x64.tar.gz:
	wget -N https://github.com/pflagerd/jglut/releases/download/v0.1.4/jdk-8u72-linux-x64.tar.gz

linux-build/Makefile: src/configure | linux-build
	cd linux-build; ../src/configure --prefix=$(directory_containing_this_makefile) WIN32= CPPFLAGS="$(CPPFLAGS)" LDFLAGS="$(LDFLAGS_LIN)"

windows-build/Makefile: src/configure | windows-build .mingw64-cross-gcc .mingw64-freeglut-devel
	cd windows-build; ../src/configure --host=x86_64-w64-mingw32 --prefix=$(directory_containing_this_makefile) WIN32=win32-dll CPPFLAGS="$(CPPFLAGS)" LDFLAGS="$(LDFLAGS_WIN)"


src/configure: src/configure.ac src/Makefile.am makefile | .autoconf .freeglut
	@printf '\nExecuting target: src/configure\n'
	cd src; autoreconf --force --install 2>/dev/null # the 2>/dev/null is to suppress info that eclipse thinks are errors

bin:
	mkdir bin
	
linux-build:
	mkdir linux-build

windows-build:
	mkdir windows-build


.autoconf:
	@version=$$(autoconf --version | head -1 | cut -d" " -f 4); if [ "$$version" == "2.69" ]; then echo $$version > .autoconf; else echo "autoconf 2.69 not found or wrong version"; fi
	# sudo zypper install autoconf


.automake:


.libtool:


.freeglut:
	@version=($$(zypper search -s freeglut-devel | head -6 | tail -1)); if [ "$${version[6]}" == "3.2.1-lp152.1.3" ]; then echo $${version[6]} > .freeglut; else echo "freeglut 3.2.1-lp152.1.3 not found or wrong version"; fi
	# sudo zypper install freeglut-devel

.gcc:


.mingw64-cross-gcc:
	@version=($$(zypper search -s mingw64-cross-gcc | head -6 | tail -1)); if [ "$${version[6]}" == "9.2.0-lp152.25.1" ]; then echo $${version[6]} > .mingw64-cross-gcc; else echo "mingw64-cross-gcc 9.2.0-lp152.25.1 not found or wrong version"; fi
	# sudo zypper install mingw64-cross-gcc


.mingw64-freeglut-devel:
	@version=($$(zypper search -s mingw64-freeglut-devel | head -6 | tail -1)); if [ "$${version[6]}" == "2.8.1-lp152.5.50" ]; then echo $${version[6]} > .mingw64-freeglut-devel; else echo "mingw64-freeglut-devel 2.8.1-lp152.5.50 not found or wrong version"; fi
	# sudo zypper install mingw64-freeglut-devel


.PHONY: clean
clean:
	rm -f .generatedHeadersAndCompiledJava
	rm -f lib/jglut.jar
	rm -rf lib64/
	rm -rf bin/
	rm -f src/com_pflager_gl.h
	rm -f src/com_pflager_glu.h
	rm -f src/com_pflager_glut.h
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
	
