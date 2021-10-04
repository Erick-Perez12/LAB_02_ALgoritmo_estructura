#include <iostream>

using namespace std;

class Node{
private:
    int value;
    Node *next; 
    Node *prev; 

    friend class DobleLinkedList;
public:
    Node();
    Node(int _value);
};

Node::Node(){
    next = nullptr;
    prev = nullptr;
    value = 0;
}

Node::Node(int _value){
    value = _value;
    next = nullptr;
    prev = nullptr;
}

class DobleLinkedList{
private:
    Node *head; 
    Node *tail;
    Node *current;
public:
    DobleLinkedList(); /// Constructor

    void InsertFront(int value);
    void InsertBack(int value);

    void RemoveFront();
    void RemoveBack();

    void Search(int value);
    void Remove(int value);

    void print();

    void Begin();                            
    void Last();                              
    void Next();                              
    void Previous();                          
    int GetDato();                            
             
    ~DobleLinkedList();
};

DobleLinkedList::DobleLinkedList(){
    head = new Node;
    tail = new Node;
    head -> next = tail;
    tail -> prev = head;
    head -> prev = nullptr;
    tail -> next = nullptr;
}

void DobleLinkedList::InsertBack(int _value){
    Node *nodenew= new Node(_value);

    nodenew -> prev = tail -> prev;
    nodenew -> next = tail;

    tail -> prev -> next = nodenew;
    tail -> prev = nodenew;

    cout<<"Insertado: "<<_value<<endl;
}


void DobleLinkedList::RemoveBack(){
    Node *nodenew = tail -> prev -> prev;

    delete tail -> prev;

    tail -> prev = nodenew;
    nodenew -> next = tail;
}

void DobleLinkedList::RemoveFront(){
    Node *nodenew = head -> next -> next;

    delete head -> prev;

    head -> next = nodenew;
    nodenew -> prev = head;
}

void DobleLinkedList::Remove(int _value){
    Node *nodenew = head -> next;
    Node *tmp1 = nodenew -> next;
    Node *tmp2 = nodenew -> prev;
    int cont = 0;

    if (head -> next != nullptr){
        while (nodenew != tail){
            if (nodenew -> value == _value){
                tmp1 -> prev = tmp2;
                tmp2 -> next = tmp1;
                cont++;
            }
            nodenew = nodenew -> next;
            tmp1 = nodenew -> next;
            tmp2 = nodenew-> prev;
        }
        if (cont == 0){
            cout<<"No encontrado" <<_value<<endl;
        }
    }
    else {
        cout <<"No existente"<<endl;
    }

}

void DobleLinkedList::Search(int _value){
    Node *nodenew = head -> next;
    int cont=0;

    if (head -> next -> value != 0){
        while (nodenew -> next != nullptr){
            if (nodenew -> value == _value){
                cout << "Se encontro " << _value <<endl;
                cont++;
            }
            nodenew = nodenew -> next;
        }
        if (cont == 0){
            cout << "No se encuentra " << _value <<endl;
        }
    }
    else {
        cout << "No existen en la lista" << endl;
    }
}

void DobleLinkedList::print(){
    Node *nodenew = head -> next;
    cout<<"Lista ";
    while (nodenew != tail){
        cout << "["<<nodenew -> value << "] ";
        nodenew = nodenew -> next;
    }
    cout <<endl;
}

void DobleLinkedList::Begin(){
    current = head -> next;
}

void DobleLinkedList::Last(){
    current = tail -> prev;
}

void DobleLinkedList::Next(){
    current = current -> next;
}

void DobleLinkedList::Previous(){
    current = current -> prev;
}

int DobleLinkedList::GetDato(){
    int aux;
    aux = current -> value;
    return aux;
}

DobleLinkedList::~DobleLinkedList(){
    while (head -> next != tail){
        RemoveBack();
    }
    delete head;
    delete tail;
}

int main()
{
    DobleLinkedList L1;
    DobleLinkedList L2;

    L1.print();
    cout<<endl;

    L1.InsertBack(1);
    L1.InsertBack(2);
    L1.InsertBack(3);
    L1.InsertBack(4);
    L1.InsertBack(5);
    L1.InsertBack(6);

    L1.print();
    L1.Search(1);
     L1.InsertBack(42);
    L1.InsertBack(45);
    L1.print();

    L2.InsertBack(7);
    L2.InsertBack(8);
    L2.InsertBack(9);
    L2.RemoveBack();
    L2.InsertBack(10);
	L2.InsertBack(11);
    L2.InsertBack(12);

	L2.print();
	
    L2.RemoveBack();
    L2.print();
    L2.InsertBack(13);
    L2.InsertBack(14);
    L2.RemoveFront();
    L2.print();
}