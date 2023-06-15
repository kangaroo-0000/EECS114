#include "dlist.h"
#include "timer.c"

int main(int argc, char** argv) 
{
    int n = strtol(argv[1], NULL, 10);
    // Create timer
    stopwatch_init ();
    struct stopwatch_t* timer = stopwatch_create (); assert (timer);
    // Create an empty list
    DList l; 
    // Add ‘n’ integers [1, 2, ...n] into the list.
    for (int i = 1; i <= n; i++) l.add_to_front(i); 
    // Generate a random nuumber between 1 and n
    int r = rand() % n + 1;
    // Start timer
    stopwatch_start (timer);
    // Search for the corresponding node in the list and remove it from the list.
    ListNode* node = l.search_value(r);
    l.remove(node);
    // Stop timer
    long double ts = stopwatch_stop (timer);
    // Add the removed item to the front of the list.
    l.add_to_front(r);
    // Print results
    printf("Time: %Lf\n", ts);
}

