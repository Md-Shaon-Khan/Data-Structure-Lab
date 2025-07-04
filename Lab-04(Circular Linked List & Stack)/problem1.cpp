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

    void insertAtBeginning(int value){
        Node* newNode = new Node(value);
        if(head==nullptr){
            newNode->next = newNode;
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next!=head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
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

    void insertAtPosition(int position, int value){
        if(position<1)
        {
            cout<<"Invalid position."<<endl;
        }
        if(position==1){
            insertAtBeginning(value);
            return;
        }
        Node* newNode = new Node(value);
        Node* temp = head;
        for(int i=1;i<position-1 && temp->next!=head;i++)
        {
            temp = temp->next;
        }
        if(temp->next == head)
        {
            insertAtEnd(value);
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
};

int main() {
    CircularLinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.traverseList();

    list.insertAtBeginning(5);
    list.traverseList();

    list.insertAtPosition(3, 15);
    list.traverseList();

    return 0;
}
