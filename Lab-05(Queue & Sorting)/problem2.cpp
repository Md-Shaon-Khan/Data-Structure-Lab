#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int value){
        data = value;
        next = nullptr;
    }
};

class myQueue
{
private:
    Node *front;
    Node *rear;

public:
    myQueue()
    {
        front = rear = nullptr;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    void enqueue(int value)
    {
        Node *newNode = new Node(value);
        

        if (rear == nullptr)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Underflow" << endl;
            return;
        }

        Node *temp = front;
        front = front->next;

        if (front == nullptr)
        {
            rear = nullptr;
        }

        delete temp;
    }

    void display()
    {
        cout<<endl;
        if(isEmpty()){
            cout<<"Empty"<<endl;
            return;
        }

        Node* temp = front;
        while(temp!= nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
                }

        cout<<endl;
    }
};

int main(){
    myQueue q;
    q.enqueue(12);
    q.enqueue(23);
    q.enqueue(89);
    q.display();
    q.dequeue();
    q.display();
}