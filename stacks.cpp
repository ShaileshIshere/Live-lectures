#include<iostream>

using namespace std;

class Stack {

    int size;
    int* arr;
    int top;

public:
    Stack(int val) : size(val), top(-1) {
        arr = new int[val];
    }

    void push(int val) {
        if(top == size-1) 
            cout << "stack ovrerflow" << endl;
        else 
            arr[++top] = val;
    }

    void pop() {
        if(top == -1) {
            cout << "stack underflow" << endl;
            return;
        }
        else 
            arr[top--] = -1;
    }

    bool isEmpty() {
        if(top == -1)
            return true;
        else    
            return false;
    }

    int getSize() {
        if(top == -1) {
            cout << "stack is empty" << endl;
            return top+1;
        }
        else 
            return top+1;
    }

    int getTop() {
        if(top == -1) {
            cout << "stack is empty" << endl;
            return top;
        }
        else    
            return arr[top];
    }

    void print() {
        cout << "top : " << top << endl;
        for(int i=0; i<getSize(); ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}; 

int main () {

    Stack st(3);
    st.push(23);
    st.push(65);
    st.push(87);
    st.print();

    cout << "size of stack : " << st.getSize() << endl;
    cout << "top element of stack : " << st.getTop() << endl;

    st.pop();
    st.pop();
    st.pop();
    st.print();
    if(st.isEmpty())
        return true;
    else 
        return false;


    return 0;
}