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
     void print(){
        Node* temp=Head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->Next;
        }
        cout<<"Null"<<endl;
    }

int keyFind(int key){
        Node*temp=Head;
        int index = 0;
        while(temp!=NULL){
            if(temp->data==key){
                return index;
            }
            temp=temp->Next;
            index++;
        }
        return -1;
    }
    int helper(Node* h,int key){
        if(h==NULL){
            return -1;
        }
        if(h->data==key){
            return 0;
        }

        int index = helper(h->Next,key);
        if(index==-1){
            return -1;
        }
        return index + 1;
    }
    int searchRec(int key){
        return helper(Head,key);
    }
};

int main(){
     List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.push_front(5);
    ll.push_front(6);
    ll.print();
   cout<<ll.searchRec(2)<<endl;
}