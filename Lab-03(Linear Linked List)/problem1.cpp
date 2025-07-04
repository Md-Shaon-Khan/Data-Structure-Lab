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

class LinkedList{
    private:
    Node* head;

    public:
    LinkedList(){
        head = nullptr;
    }

    void insertAtBeginning(int value){
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int value){
        Node* newNode = new Node(value);

        if(head == nullptr)
        {
            head = newNode;
            return;
        }

        Node* temp = head;

        while(temp->next!=nullptr){
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void insertAtPosition(int position, int value){
        Node* newNode = new Node(value);

        if(position<1){
            cout << "Invalid position. Position should be >= 1.\n";
            return;
        }

        if(position==1)
        {
            insertAtBeginning(value);
            return;
        }

        Node* temp = head;

        for(int i=1;i<position-1;i++)
        {
            temp = temp->next;
        }

        if(temp==nullptr)
        {
            cout << "Position is beyond list length. Inserting at end.\n";
            insertAtEnd(value);
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void traverseList()
    {
        Node* temp = head;
        cout<<"LinkedList elements: ";

        while(temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }

        cout<<endl;
    }

};

int main(){
    LinkedList list;


    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.traverseList();


    list.insertAtBeginning(5);
    list.traverseList();

    
    list.insertAtPosition(3, 15); 
    list.traverseList();

   
    list.insertAtPosition(10, 50);
    list.traverseList();

    return 0;
}