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
    };
class List{
    Node* Head;
    Node* Tail;
    public:
    List(){
        Head=NULL;
        Tail=NULL;
    }
    //For Insertion from Front
    // void push_front(int val){
    //     Node* newNode= new Node(val);
    //     if(Head==NULL){
    //         Head=Tail=newNode;
    //     }
    //     else{
    //         newNode->Next=Head;
    //         Head=newNode;
    //     }
    // }
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
    void print(){
        Node* temp=Head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->Next;
        }
        cout<<"Null";
    }
   
};


int main(){
  
    List ll;
    // ll.push_front(1);
    // ll.push_front(2);
    // ll.push_front(3);
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.print();
 
    return 0;
}