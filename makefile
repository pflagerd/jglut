SHELL = /bin/bash

directory_containing_this_makefile=$(dir $(realpath $(firstword $(MAKEFILE_LIST))))

CPPFLAGS=\
	-std=gnu99\
	-O0\
	-g3\
	-m64\
	-Wall\
	-I$(directory_containing_this_makefile)freeglut-3.2.1/include\
	-I$(directory_containing_this_makefile)jdk1.8.0_72/include\
	-I$(directory_containing_this_makefile)jdk1.8.0_72/include/linux\
	-I$(directory_containing_this_makefile)src

LDFLAGS_LIN=\
	-Wl,--no-as-needed\
	-Wl,--start-group\
	$(directory_containing_this_makefile)freeglut-3.2.1/lib/libglut.a -lGLU -lGL -lX11 -lXrandr -lXxf86vm -lXi\
	-Wl,--end-group -Wl,--no-undefined -Wl,--no-allow-shlib-undefined
	
LDFLAGS_WIN=\
	-Wl,--no-as-needed\
	-Wl,--start-group\
	-L/usr/lib64 -lglut -lglu32 -lopengl32\
	-Wl,--end-group


.PHONY: all
all: linux # windows

.PHONY: package jar
jar package: lib/jglut.jar

lib/jglut.jar: bin/libjglut.so # bin/libjglut.dll bin/libglut-0.dll
	strip bin/libjglut.so
	# /usr/x86_64-w64-mingw32/bin/strip bin/libjglut.dll
	cp src/com/pflager/*.java bin/com/pflager
	jar cf lib/jglut.jar -C bin com -C bin libjglut.so # -C bin libglut-0.dll -C bin libjglut.dll
	
.PHONY: linux
linux: bin/libjglut.so

.PHONY: windows
windows: bin/libjglut.dll bin/libglut-0.dll

bin/libjglut.so: lib/libjglut.so
	cp -f lib/libjglut.so bin/libjglut.so
	cp -f lib/libjglut.so src/libjglut.so

src/libjglut.dll: bin/libjglut.dll
	cp -f bin/libjglut.dll src/libjglut.dll

bin/libglut-0.dll: src/libglut-0.dll
	- mkdir bin
	cp -f src/libglut-0.dll bin/libglut-0.dll

lib/libjglut.so: linux-build/.libs/libjglut.so
	cd linux-build; $(MAKE) install
	touch lib/libjglut.so # this may be unnecessary

bin/libjglut.dll: windows-build/.libs/libjglut.a
	cd windows-build; $(MAKE) install
	touch bin/libjglut.dll # this may be unnecessary

# generatedHeadersAndCompiledJava stands for src/com_pflager_glut.h src/com_pflager_glu.h src/com_pflager_gl.h bin/com
	
linux-build/.libs/libjglut.so: linux-build/Makefile generatedHeadersAndCompiledJava src/*.c src/*.h
	cd linux-build; $(MAKE) && touch .libs/libjglut.so
	
windows-build/.libs/libjglut.a: windows-build/Makefile generatedHeadersAndCompiledJava src/*.c src/*.h
	cd windows-build; $(MAKE) && touch .libs/libjglut.a	

generatedHeadersAndCompiledJava: jdk1.8.0_72/bin/javac src/com/pflager/*.java
	- mkdir bin
	jdk1.8.0_72/bin/javac -g -d bin -h src src/com/pflager/*.java
	touch generatedHeadersAndCompiledJava

jdk1.8.0_72/bin/javac: jdk-8u72-linux-x64.tar.gz
	tar xzf jdk-8u72-linux-x64.tar.gz && touch jdk1.8.0_72/bin/javac
	
jdk-8u72-linux-x64.tar.gz:
	wget -N https://github.com/pflagerd/jglut/releases/download/v0.1.4/jdk-8u72-linux-x64.tar.gz

linux-build/Makefile: src/configure freeglut-3.2.1/include/GL/freeglut.h freeglut-3.2.1/lib/libglut.a | linux-build
	cd linux-build; ../src/configure --prefix=$(directory_containing_this_makefile) WIN32= CPPFLAGS="$(CPPFLAGS)" LDFLAGS="$(LDFLAGS_LIN)"

windows-build/Makefile: src/configure | windows-build
	cd windows-build; ../src/configure --host=x86_64-w64-mingw32 --prefix=$(directory_containing_this_makefile) WIN32=win32-dll CPPFLAGS="$(CPPFLAGS)" LDFLAGS="$(LDFLAGS_WIN)"


src/configure: src/configure.ac src/Makefile.am makefile
	@printf '\nExecuting target: src/configure\n'
	cd src; autoreconf --force --install 2>/dev/null # the 2>/dev/null is to suppress info that eclipse thinks are errors

freeglut-3.2.1/include/GL/freeglut.h freeglut-3.2.1/lib/libglut.a:
	sudo apt install freeglut3-dev
	
linux-build:
	mkdir linux-build

windows-build:
	mkdir windows-build
	
	
.PHONY: clean
clean:
	rm -f generatedHeadersAndCompiledJava
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
	
