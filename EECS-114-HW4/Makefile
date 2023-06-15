CFLAGS = -Wall -Werror -g -O3 -std=c99
CC = gcc
EXEC = prim

${EXEC}: prim.o graph.o heap.o node.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f *.o ${EXEC}
