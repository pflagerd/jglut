SHELL = /bin/bash

directory_containing_this_makefile=$(dir $(realpath $(firstword $(MAKEFILE_LIST))))

CPPFLAGS=\
	-std=gnu99\
	-O0\
	-g3\
	-m64\
	-Wall\
	-I$(directory_containing_this_makefile)/jdk1.8.0_72/include\
	-I$(directory_containing_this_makefile)/jdk1.8.0_72/include/linux\
	-I$(directory_containing_this_makefile)src

LDFLAGS=\
	-Wl,--no-as-needed\
	-Wl,--start-group\
	-L/usr/lib64 -lglut -lGLU -lGL\
	-Wl,--end-group -Wl,--no-undefined -Wl,--no-allow-shlib-undefined

.PHONY: all
all: bin/libjglut.so
	$(MAKE) -f makefile.win32
	
bin/libjglut.so: lib64/libjglut.so bin
	cp -f lib64/libjglut.so bin/libjglut.so
	cp -f lib64/libjglut.so src/libjglut.so

bin:
	mkdir bin
	
lib64/libjglut.so: build-linux/.libs/libjglut.so
	cd build-linux; $(MAKE) install

build-linux/.libs/libjglut.so: build-linux/Makefile src/com_pflager_gl.h src/com_pflager_glu.h src/com_pflager_glut.h src/*.c src/*.h
	cd build-linux; $(MAKE) -j 16; touch .libs/libjglut.so

src/com_pflager_glut.h src/com_pflager_glu.h src/com_pflager_gl.h: jdk1.8.0_72/bin/javac src/com/pflager/*.java
	jdk1.8.0_72/bin/javac -cp bin -h src src/com/pflager/*.java
	
jdk1.8.0_72/bin/javac: jdk-8u72-linux-x64.tar.gz
	tar xzf jdk-8u72-linux-x64.tar.gz && touch jdk1.8.0_72/bin/javac
	
jdk-8u72-linux-x64.tar.gz:
	wget -N https://github.com/pflagerd/jglut/releases/download/v0.1.4/jdk-8u72-linux-x64.tar.gz

build-linux/Makefile: src/configure
	@printf '\nExecuting target: build-linux/Makefile\n'
	@printf "SHELL=$(SHELL)\n"
	@printf "$(directory_containing_this_makefile)src/configure\n"
	@printf "$(dir $(directory_containing_this_makefile))src/configure\n"
	@printf "CPPFLAGS=$(CPPFLAGS)\n"
	@printf "LDFLAGS=$(LDFLAGS)\n"
	- mkdir build-linux
	cd build-linux; ../src/configure --prefix=$(directory_containing_this_makefile) WIN32= CPPFLAGS="$(CPPFLAGS)" LDFLAGS="$(LDFLAGS)"

.PHONY: autoreconf
src/configure: src/configure.ac src/Makefile.am makefile
	@printf '\nExecuting target: src/configure\n'
	cd src; autoreconf --force --install 2>/dev/null # the 2>/dev/null is to suppress info that eclipse thinks are errors

.PHONY: clean
clean:
	rm -f lib64/*
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
	rm -rf build-linux
	rm -rf build-windows
	
