#include<iostream>
#include<deque>

using namespace std;

class Deque {
public:
    int* arr, size, front, rear;

    Deque(int size) {
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }

    void push_front(int val) {
        // overflow
        if((front == 0 && rear == size-1) || (rear == front - 1)) {
            cout << "Dequeue overflow" << endl;
            return;
        }

        // empty case
        else if(front == -1 && rear == -1) {
            front++;
            rear++;
            arr[front] = val;
        }

        // circular nature
        else if(front == 0 && rear != size-1) {
            front = size-1;
            arr[front] = val;
        }

        // normal case
        else {
            front--;
            arr[front] = val;
        }
    }

    void pop_front() {
        // underflow
        if(front == -1 && rear == -1) {
            cout << "Dequeue underflow" << endl;
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

    void push_back(int val) {
        // overflow
        if((front == 0 && rear == size-1) || (rear == front - 1)) {
            cout << "Dequeue overflow" << endl;
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

    void pop_back() {
        // underflow
        if(front == -1 && rear == -1) {
            cout << "Deque underflow" << endl;
        }

        // single element
        else if(front == rear) {
            arr[rear] = -1;
            front = -1;
            rear = -1;
        }

        // circular case
        else if(rear == 0) {
            arr[rear] = -1;
            rear = size-1;
        }

        // normal flow
        else {
            arr[rear] = -1;
            rear--;
        }
    }

    void print() {
        cout << "front : " << front << " " << "rear : " << rear << endl;
        for(int i=0; i<size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {

    Deque dq(5);
    dq.push_front(10);
    dq.print();
    
    dq.push_front(20);
    dq.print();
    
    dq.push_front(30);
    dq.print();
    
    dq.push_front(40);
    dq.print();
    
    dq.push_front(50);
    dq.print();

    dq.push_front(60);
    dq.print();

    dq.pop_front();
    dq.print();


    return 0;
}