lab6: lab6.o lab6_utils.o 
	gcc -o lab6 lab6.o lab6_utils.o

lab6.o: lab6.c lab6_utils.h
	gcc -c lab6.c
 
lab6_utils.o: lab6_utils.c
	gcc -c lab6_utils.c

clean: 
	rm lab6 *.o

