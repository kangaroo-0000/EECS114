#include "queue.h"

#include <cstdlib>
#include <ctime>

#include "timer.c"

float get_random_float();
char* convert_to_scientific_notation(long double time);

int main(int argc, char** argv) {
  // Create timer
  stopwatch_init();
  struct stopwatch_t* timer = stopwatch_create();
  assert(timer);
  // Seed random number
  srand(time(NULL));
  // Get command line arguments
  int n = strtol(argv[1], NULL, 10);
  int t = strtol(argv[2], NULL, 10);
  printf("n: %d, t: %d\n", n, t);
  // Start timer
  stopwatch_start(timer);
  // Create an empty queue
  Queue q;
  for (int i = 0; i < n; i++)
    q.enqueue(get_random_float());  // Enqueue n random floating point numbers
                                    // into the queue.
  // Do the pair of operations: dequeue a floating point number x and then
  // enqueue x, t times.
  for (int i = 0; i < t; i++) {
    float x = q.dequeue();
    q.enqueue(x);
  }
  // Stop timer
  long double ts = stopwatch_stop(timer);
  printf("Average Time: %Le\n", ts);
}

float get_random_float() { return (float)rand() / (float)RAND_MAX; }
