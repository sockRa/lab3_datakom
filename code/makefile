lab3: node0.o node1.o node2.o node3.o prog3.o
	gcc -Wall -o lab3 node0.o node1.o node2.o node3.o prog3.o
node0.o: node0.c prog3.h
	gcc -c node0.c
node1.o: node1.c prog3.h
	gcc -c node1.c
node2.o: node2.c prog3.h
	gcc -c node2.c
node3.o: node3.c prog3.h
	gcc -c node3.c
prog3.o: prog3.c prog3.h
	gcc -c prog3.c
clean:
	rm *.o