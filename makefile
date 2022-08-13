a.out : main.o processors_num.o
	gcc -g -Wall -std=c99 main.o processors_num.o -o a.out

main.o : main.c main.h
	gcc -c -Wall -std=c99 main.c -o  main.o

processors_num.o : processors_num.c processors_num.h
	gcc -c -Wall -std=c99 processors_num.c -o processors_num.o

clean:
	rm *.o
	rm a.out
