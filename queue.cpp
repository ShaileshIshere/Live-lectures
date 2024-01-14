#include <iostream>
using namespace std;

class Circular_queue {
  public:
    int* arr;
    int size;
    int front;
    int rear;

    Circular_queue(int size) {
      arr = new int[size];
      this->size = size;
      front = -1;
      rear = -1;
    }

    void push(int val) {
      // overflow
      if((front == 0 && rear == size-1) || (rear == front - 1)) {
        cout << "queue overflow" << endl;
        return;
      }

      // empty queue
      else if(front == -1 && rear == -1) {
        front++;
        rear++;
        arr[rear] = val;
      }

      // circular nature
      else if(rear == size-1 && front != 0) {
        rear = 0;
        arr[rear] = val;
      }

      // normal flow
      else {
        rear++;
        arr[rear] = val;
      }
    }

    void pop() {
      // underflow
      if(front == -1 && rear == -1) {
        cout << "queue underflow" << endl;
        return;
      }

      // single element
      else if(front == rear) {
        arr[front] = -1;
        front = -1;
        rear = -1;
      }

      // circular nature
      else if(front == size-1) {
        arr[front] = -1;
        front = 0;
      }

      // normal flow
      else {
        arr[front] = -1;
        front++;
      }
    }

    void print() {
      cout << "printing queue" << endl;
      cout << "front : " << front << " " << "rear : " << rear << endl;
      for(int i=0; i<size; ++i) {
        cout << arr[i] << " ";
      }
      cout << endl;
    }
};

int main() {
  Circular_queue q(4);

  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);
  q.print();

  q.pop();
  q.pop();
  q.pop();
  q.print();

  q.push(20);
  q.print();

  q.pop();
  q.print();
    
  return 0;
}