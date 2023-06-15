#include "queue.h"

Queue::Queue()
{
  /* initialize your data */
  size = 0;
  capacity = 10;
  data = new float[capacity];
  front = 0;
  rear = 0;
}

Queue::~Queue()
{
  /* destroy your data */
  delete[] data;
}

void Queue::enqueue(float value)
{
  /* add your code here */
  if (size == capacity)
  {
    float* temp = new float[capacity*2];
    for (int i = 0; i < size; i++)
    {
      temp[i] = data[(front+i)%capacity];
    }
    delete[] data;
    data = temp;
    front = 0;
    rear = size;
    capacity *= 2;
  }
  data[rear] = value;
  rear = (rear+1)%capacity;
  size++;
}

float Queue::dequeue()
{
  /* add your code here */
  if (size == 0)
  {
    return 0;
  }
  float temp = data[front];
  front = (front+1)%capacity;
  size--;
  return temp;
}
