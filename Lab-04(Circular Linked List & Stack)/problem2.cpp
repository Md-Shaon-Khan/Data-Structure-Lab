#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int value){
        data = value;
        next = nullptr;
    }
};

class CircularLinkedList{
    private:
    Node* head;

    public:
    CircularLinkedList(){
        head = nullptr;
    }

    void traverseList(){
        if(head==nullptr){
            cout<<"Circular Linked List is Empty."<<endl;
            return;
        }

        Node* temp = head;
        cout<<"Circular Linked List elements: ";
        do{
            cout<<temp->data<<" ";
            temp = temp->next;
        }while (temp != head);  
        cout<<endl;
    }

    void insertAtEnd(int value){
        Node* newNode = new Node(value);
        if(head==nullptr)
        {
            newNode->next = newNode;
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head; 
    }

    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }
        if (head->next == head) {
            delete head;
            head = nullptr;
            cout << "Node deleted from beginning (only node).\n";
            return;
        }
        Node* temp = head;
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        head = head->next;
        last->next = head;
        delete temp;
        cout << "Node deleted from beginning.\n";
    }

    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }
        if (head->next == head) {
            delete head;
            head = nullptr;
            cout << "Node deleted from end (only node).\n";
            return;
        }
        Node* temp = head;
        Node* prev = nullptr;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        delete temp;
        cout << "Node deleted from end.\n";
    }

    void deleteFromPosition(int position) {
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }
        if (position < 1) {
            cout << "Invalid position. Position should be >= 1.\n";
            return;
        }
        if (position == 1) {
            deleteFromBeginning();
            return;
        }
        Node* temp = head;
        for (int i = 1; i < position-1 && temp->next != head; i++) {
            temp = temp->next;
        }
        if (temp->next == head) {
            cout << "Position is beyond list length. Nothing to delete.\n";
            return;
        }
        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
        cout << "Node deleted from position " << position << ".\n";
    }
};

int main() {
    CircularLinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.traverseList();

    list.deleteFromBeginning();
    list.traverseList();

    list.deleteFromEnd();
    list.traverseList();

    list.deleteFromPosition(2);
    list.traverseList();

    list.deleteFromBeginning();
    list.deleteFromBeginning();
    list.traverseList();

    list.deleteFromBeginning();

    return 0;
}