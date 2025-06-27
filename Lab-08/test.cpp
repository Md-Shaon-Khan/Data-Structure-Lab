#include<bits/stdc++.h>
using namespace std;

struct Node{
   int data;
   Node* left;
   Node* right;
};

Node* createNode(int value){
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;


    return newNode;
}

Node* insertTree(Node* root,int value){
    if(root==nullptr){
        return createNode(value);
    }

    if(value<root->data){
        root->left = insertTree(root->left,value);
    }
    else{
        root->right =insertTree(root->right,value);
    }

    return root;
}

Node* searchTree(Node* root,int key){
    if(root==nullptr){
        return nullptr;
    }
    if(root->data==key){
        return root;
    }
    else if(root->data > key){
        return searchTree(root->left,key);
    }
    else{
        return searchTree(root->right,key);
    }
}
Node* findMin(Node* root){
    if(root && root->left!=nullptr){
        root->left = findMin(root->left);
    }
    return root;
}
Node* deleteNode(Node* root,int key){
    if(root==nullptr){
        return root;
    }
    if(key<root->data){
        root->left = deleteNode(root->left,key);
    }
    else if(key>root->data){
        root->right = deleteNode(root->right,key);
    }
    else{
        if(root->left==nullptr && root->right==nullptr){
            delete root;
            return nullptr;
        }
        else if(root->left==nullptr){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right==nullptr){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else{

             Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right,temp->data);
        }
       
        
    }
    return root;
}


void inorderTraversal(Node* root){
    if(root==nullptr){
        return;
    }
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}


int main(){
    int n,value;
    cout<<"How many nodes want to insert: ";
    cin>>n;
    Node* root = nullptr;
    cout<<"Enter the values: ";
    for(int i=1;i<=n;i++){
        cin>>value;
        root = insertTree(root,value);
    }

    inorderTraversal(root);

    int key;
    Node* found = nullptr;
    cout<<"\nEnter a value to search at tree: ";
    cin>>key;

    found = searchTree(root,key);

    if(found!=nullptr){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }

    cout<<"Enter the value to delete: ";
    cin>>key;
    found = deleteNode(root,key);
    inorderTraversal(found);



    return 0;
}