#include<iostream>

using namespace std;
#define size 10

class Queue
{
    int a[size];
    int tail;   
    int head;  
    
    public:
    Queue();
    void push(int x);     
    int pop();
    void print();
    int top();
};

Queue::Queue() {
    tail = head = -1;
}

void Queue::push(int x)
{
    if(head == -1) {
        head++;
    }
    if( tail == size-1)
    {
        cout << "FULL";
    }
    else
    {
        a[++tail] = x;
    }
}

int Queue::pop()
{
    return a[++head];
}

int Queue::top()
{
    return a[head];
}

void Queue::print()
{
    int i;
    for( i = head; i <= tail; i++)
    {
        cout << a[i] << endl;
    }
}

int main()
{
    Queue L;
    L.push(11);
    L.push(12);
    L.push(13);
    L.push(14);
    L.push(15);
    L.push(16);
    L.push(17);
    L.print();
    cout<<"--------------"<<endl;
    L.pop();
    L.push(18);
    L.pop();
    L.pop();
    L.push(19);
    
    L.print();
    cout<<"Ultimo: "<<L.top()<<endl;
    
    return 0;
}