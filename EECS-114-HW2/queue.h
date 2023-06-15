#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
  public:
  Queue();
  ~Queue();
  Queue& operator=(const Queue& q);
  void enqueue(float value);
  float dequeue();

  private:
  /* declare your data */
  int size;
  int capacity;
  float* data;
  int front;
  int rear;
};

#endif // QUEUE_H
