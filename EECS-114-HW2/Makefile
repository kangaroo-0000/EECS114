CC = g++
CFLAGS = -std=c++98
COPTFLAGS = -O3 -g
LDFLAGS =

# queue
queue_test: queue_test.o queue.o 
	$(CC) $(COPTFLAGS) -o $@ $^

# dlist
dlist_test: dlist_test.o dlist.o
	$(CC) $(COPTFLAGS) -o $@ $^

%.o: %.cc
	$(CC) $(CFLAGS) $(COPTFLAGS) -o $@ -c $<

clean:
	rm -f core *.o *~ queue_test dlist_test