#include <bits/stdc++.h>
 
using namespace std;
#define size 10
 
//problema 1

class Stack {
    int Top;
 
public:
    int a[size]; 
 
    Stack() { Top = -1; }
    bool push(int x);
    int pop();
    int top();
};
 
bool Stack::push(int x) {
    if (Top >= (size - 1)) {
        return false;
    }
    else {
        a[++Top] = x;
        cout<<"elemento: "<<x<<endl;
        return true;
    }
}
 
int Stack::pop() {
    if (Top < 0) {
        return 0;
    }
    else {
        int x = a[Top--];
        return x;
    }
}

int Stack::top() {
    return a[Top];
}

int main()
{
    class Stack L;
    L.push(23);
    L.push(453);
    L.push(13);
    L.push(46);
    L.push(12);
    cout <<"Nro eliminado"<<L.pop()<<endl;
    cout<<"Ultimo elemento : "<<L.top();

    return 0;
}