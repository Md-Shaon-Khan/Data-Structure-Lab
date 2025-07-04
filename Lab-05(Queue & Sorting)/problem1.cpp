#include<bits/stdc++.h>
using namespace std;

#define max 12

class CircularQueue{
   
    private:
    int queue[max];
    int front,rear,count;

    public:
    CircularQueue(){
        front = -1;
        rear = -1;
        count = 0;
    }

    void enqueue(int item){
        if(count == max){
            cout<<"Overflow"<<endl;
            return;
        }

        if(count==0)
        {
            front = rear = 0;
        }
        else if(rear == max - 1){
            rear = 0;
        }
        else{
            rear = rear + 1;
        }

        queue[rear] = item;

        count++;

    }

    void dequeue(){
        if(count == 0){
            cout<<"Underflow"<<endl;
            return;
        }

        int item = queue[front];

        if(front == max - 1){
            front = 0;
        }
        else{
            front = front + 1;
        }

        count--;

    }

    void display(){
        if(count == 0)
        {
            cout<<"Empty\n";
            return;
        }

        cout<<"Queue elements: ";
        int index = front;
        for(int i=0;i<count;i++){
            cout<<queue[index]<<" ";
            index = (index+1)%max;
        }
        cout<<endl;

    }
};

int main(){

    CircularQueue q;
    int choice, item;

    while (true) {
        cout << "\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter item to insert: ";
                cin >> item;
                q.enqueue(item);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
    
}