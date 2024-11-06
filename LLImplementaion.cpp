#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* Next;

    Node(int val){
    data=val;
    Next=NULL;
        }
     ~Node(){
        cout<<"Destructer Call For "<<data<<endl;
        if(Next!=NULL){
            delete Next;
            Next=NULL;
        }
     }
    };
class List{
    Node* Head;
    Node* Tail;
    public:
    List(){
        Head=NULL;
        Tail=NULL;
    }
    //For Delete Linked List
    ~List(){
        cout<<"List destructor Counter"<<endl;
        if(Head!=NULL){
            delete Head;
            Head = NULL;
        }
    }
    //For Insertion from Front
    void push_front(int val){
        Node* newNode= new Node(val);
        if(Head==NULL){
            Head=Tail=newNode;
        }
        else{
            newNode->Next=Head;
            Head=newNode;
        }
    }
    // For Insertion from Back
    void push_back(int val){
        Node* newNode= new Node(val);
        if(Tail==NULL){
            Head=Tail=newNode;
        }
        else{
            Tail->Next=newNode;
            Tail=newNode;
        }
    }
    // For Mid Insertion
    void push_mid(int val,int pos){
        Node* newNode= new Node(val);
        Node* temp=Head;
        for(int i=0; i<pos-1;i++){
            temp=temp->Next;
        }
        newNode->Next=temp->Next;
        temp->Next=newNode;
    }
    // Print LL
    void print(){
        Node* temp=Head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->Next;
        }
        cout<<"Null"<<endl;
    }
   
};


int main(){
  
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);
    ll.push_mid(1000,3);

    ll.print();
 
    return 0;
}