gcc -m64 -g3 -I../../jdk1.8.0_72/include -I ../../jdk1.8.0_72/include/linux LinkTest.c -Wl,--no-as-needed -Wl,--start-group -L/usr/lib64 -L../lib64 -ljglut -lglut -lGLU -lGL -Wl,--end-group -o LinkTest
export LD_LIBRARY_PATH=$HOME/Downloads/jglut/JGlut/lib64
./LinkTest
