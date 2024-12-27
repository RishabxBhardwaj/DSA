#include <iostream>
using namespace std;

// ===============================
// Node Class: Represents each node in the Linked List
// ===============================
class Node {
public:
    int data;       // Stores the value of the node
    Node* next;     // Pointer to the next node

    // Constructor: Initializes the node with a value and sets next to NULL
    Node(int val) {
        data = val;
        next = NULL;
    }

    // Destructor: Cleans up the node and deletes subsequent nodes recursively
    ~Node() {
        cout << "Node destructor called" << endl;
        if (next != NULL) {
            delete next;
            next = NULL;
        }
    }
};

// ===============================
// List Class: Represents the Linked List
// ===============================
class List {
    Node* Head;   // Pointer to the head node
    Node* Tail;   // Pointer to the tail node

public:
    // Constructor: Initializes an empty list
    List() {
        Head = NULL;
        Tail = NULL;
    }

    // Destructor: Cleans up the entire list
    ~List() {
        cout << "List destructor called" << endl;
        while (Head != NULL) {
            popFront();
        }
    }

    // ===============================
    // Print Linked List
    // ===============================
    void printLL() {
        Node* temp = Head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // ===============================
    // Insert Node at the Front
    // ===============================
    void pushFront(int val) {
        Node* newNode = new Node(val);
        if (Head == NULL) {
            Head = Tail = newNode; // First node in the list
        } else {
            newNode->next = Head;
            Head = newNode;
        }
    }

    // ===============================
    // Insert Node at the End
    // ===============================
    void pushBack(int val) {
        Node* newNode = new Node(val);
        if (Head == NULL) {
            Head = Tail = newNode; // First node in the list
        } else {
            Tail->next = newNode;
            Tail = newNode;
        }
    }

    // ===============================
    // Insert Node at a Specific Position
    // ===============================
    void pushMid(int val, int pos) {
        if (pos == 0) {
            pushFront(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* temp = Head;

        for (int i = 0; i < pos - 1; i++) {
            if (temp == NULL || temp->next == NULL) {
                cout << "Position out of range!" << endl;
                delete newNode;
                return;
            }
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        if (newNode->next == NULL) {
            Tail = newNode;
        }
    }

    // ===============================
    // Remove Node from the Front
    // ===============================
    void popFront() {
        if (Head == NULL) {
            cout << "List is already empty!" << endl;
            return;
        }
        Node* temp = Head;
        Head = Head->next;
        temp->next = NULL;
        delete temp;

        if (Head == NULL) {
            Tail = NULL; // List became empty
        }
    }

    // ===============================
    // Remove Node from the End
    // ===============================
    void popBack() {
        if (Head == NULL) {
            cout << "List is already empty!" << endl;
            return;
        }

        if (Head == Tail) { // Only one node in the list
            delete Head;
            Head = Tail = NULL;
            return;
        }

        Node* temp = Head;
        while (temp->next != Tail) {
            temp = temp->next;
        }

        delete Tail;
        Tail = temp;
        Tail->next = NULL;
    }

    // ===============================
    // Search Node Iteratively
    // ===============================
    int Search(int key) {
        int pos = 0;
        Node* temp = Head;
        while (temp != NULL) {
            if (temp->data == key) {
                return pos;
            }
            pos++;
            temp = temp->next;
        }
        return -1; // Key not found
    }

    // ===============================
    // Search Node Recursively
    // ===============================
    int helper(Node* temp, int key) {
        if (temp == NULL) {
            return -1; // Base case: end of list
        }
        if (temp->data == key) {
            return 0; // Found key at current node
        }
        int index = helper(temp->next, key);
        return (index == -1) ? -1 : index + 1;
    }

    int SearchRec(int key) {
        return helper(Head, key);
    }
};

// ===============================
// Main Function
// ===============================
int main() {
    List ll;
    ll.pushFront(1);
    ll.pushFront(2);
    ll.pushFront(3);
    ll.pushFront(4);
    ll.pushBack(5);
    ll.pushBack(6);
    ll.pushBack(7);
    ll.pushBack(8);
    ll.pushMid(100, 4);
    ll.popFront();
    ll.popBack();

    ll.printLL();
    cout << "Position of 100: " << ll.SearchRec(100) << endl;

    return 0;
}
