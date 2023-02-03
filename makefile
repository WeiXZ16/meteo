abr.o: abr.c abr.h
        gcc -c abr.c  -o abr.o -wall
main.o: main.c abr.h
        gcc -c main.c  -o main.o -wall
        
        
