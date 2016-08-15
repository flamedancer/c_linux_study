a.out : main.o getch.o getop.o stack.o
	gcc -o a.out getch.o getop.o stack.o main.o

main.o : main.c
	gcc -c main.c head.h

getch.o : getch.c
	gcc -c getch.c

getop.o : getop.c 
	gcc -c getop.c head.h

stack.o : stack.c
	gcc -c stack.c

.PHONY: clean
clean :
	rm -f *.o a.out
