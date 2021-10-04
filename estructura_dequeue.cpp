#include<iostream>

using namespace std;
#define size 10
//problema 4
class Dequeue {
   int a[100],h,t;
   public:
      Dequeue();
      void pushfront(int);
      void pushback(int);
      void popfront();
      void popback();
      void print();
};

Dequeue::Dequeue() {
   h=-1;
   t=-1;
}

void Dequeue::pushback(int i) {
   if(t>=size-1) {
      cout<<"No overflow"<<endl;
   } else {
      if(h==-1) {
         h++;
         t++;
      } else {
         t=t+1;
      }
      a[t]=i;
      cout<<"Insertado:"<<a[t]<<endl;
   }
}

void Dequeue::pushfront(int i) {
   if(h==-1) {
      h=0;
      a[++t]=i;
      cout<<"Insertado:"<<i<<endl;
   } else if(h!=0) {
      a[--h]=i;
      cout<<"Insertado:"<<i<<endl;
   } else {
      cout<<"No overflow"<<endl;
   }
}

void Dequeue::popfront() {
   if(h==-1) {
      cout<<"No existe";
      return;
   }
   else {
      cout<<"Eliminado:"<<a[h]<<endl;
      if(h==t) {
         h=-1;
         t=-1;
         return;
      } else
         h=h+1;
      }
}

void Dequeue::popback() {
    if(h==-1) {
        cout<<"No existe";
        return;
    }
    else{
        cout<<"Eliminado:"<<a[t]<<endl;
        if(h==t) {
            h=-1;
            t=-1;
         }
        else
            t=t-1;
    }
}

void Dequeue::print() {
    if(h==-1) {
        cout<<"no existe";
    } 
    else {
        cout<<"LISTA: ";
        for(int i=h;i<=t;i++) {
            cout<<"["<<a[i]<<"] ";
        }
         cout<<endl;
    }
}

int main() {
    int i;
    Dequeue L;
    L.pushfront(23);
    L.pushback(34);
    L.pushback(65);
    L.pushback(57);
    
    L.pushback(32);
    L.print();
    L.popfront();
    L.popback();
    
    L.pushback(98);
    L.print();
}