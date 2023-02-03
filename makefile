abr.o: abr.c abr.h
        gcc -c abr.c  -o abr.o 
main.o: main.c abr.h
        gcc -c main.c  -o main.o 
exec: main.o abr.o avl.o
      gcc main.o abr.o avl.o -exec 
clear:
      rm -f *.o  
