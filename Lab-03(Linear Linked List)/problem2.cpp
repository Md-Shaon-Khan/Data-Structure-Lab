#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = nullptr;
    }
};

class LinkedList
{
    private:
    Node* head;
    
    public:
    LinkedList(){
        head = nullptr;
    }

    void insertAtEnd(int value){
        Node* newNode = new Node(value);

        if(head == nullptr){
            head = newNode;
            return;
        }

        Node* temp = head;

        while(temp->next!=nullptr){
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void traverseList() {
        Node* temp = head;
        cout << "Linked List elements: ";
        while (temp != nullptr) {
            cout << temp->data << "  ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void deleteFromBeginning(){
        if(head==nullptr){
            cout<<"List is already empty\n";
        }

        Node* temp = head;

        head = head->next;
        delete temp;
        cout<<"Node deleted from beginning\n";
    }

    void deleteFromEnd(){
        if(head==nullptr){
            cout<<"List is already empty\n";
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            cout << "Node deleted from end (only node).\n";
            return;
        }

        Node* temp = head;
        while(temp->next->next != nullptr)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
        cout<<"Node deleted from end.\n";

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
        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr) {
            cout << "Position is beyond list length. Nothing to delete.\n";
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
        cout << "Node deleted from position " << position << ".\n";
    }

};

int main(){
    LinkedList list;


    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(50);
    list.traverseList();


    list.deleteFromBeginning();
    list.traverseList();


    list.deleteFromEnd();
    list.traverseList();


    list.deleteFromPosition(2); 
    list.traverseList();

    list.deleteFromPosition(10);
    list.traverseList();


    list.deleteFromBeginning();
    list.deleteFromBeginning();
    list.traverseList();


    list.deleteFromBeginning();

    return 0;
}