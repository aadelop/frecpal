frecpal: frecpal.o linkedList.o frecLib.o
	gcc -o frecpal frecpal.o linkedList.o frecLib.o

frecpal.o: frecpal.c
	gcc -c frecpal.c

linkedList.o: linkedList.c linkedList.h
	gcc -c linkedList.c

frecLib.o: frecLib.c frecLib.h
	gcc -c frecLib.c