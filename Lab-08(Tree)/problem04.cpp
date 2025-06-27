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

Node* insertionTree(Node* root,int value){

   if(root==nullptr){
    return createNode(value);
   }

   if(value<root->data){
    root->left = insertionTree(root->left,value);
   }
   else{
    root->right = insertionTree(root->right,value);
   }

   return root;

}

Node* searchTree(Node* root,int key){

   if(root==nullptr || root->data==key){
    return root;
   }

   if(key<root->data){
    return searchTree(root->left,key);
   }
   else{
    return searchTree(root->right,key);
   }

}

Node* findMin(Node* root){

   while(root && root->left!=nullptr){
    root = root->left;
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

int main() {
    Node* root = nullptr;
    int n, value;

    cout << "How many values do you want to insert in the BST? ";
    cin >> n;

    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        root = insertionTree(root, value);
    }

    cout << "\nInorder Traversal of BST (Before Deletion): ";
    inorderTraversal(root);
    cout << endl;

    cout << "\nEnter value to delete from BST: ";
    int key;
    cin >> key;

    root = deleteNode(root, key);

    cout << "\nInorder Traversal of BST (After Deletion): ";
    inorderTraversal(root);
    cout << endl;

    cout<<"\nEnter an item for search: ";
    cin>>key;
    Node* found = searchTree(root,key);
    if(found!=nullptr){
        cout<<"FOUND"<<endl;
    }
    else{
        cout<<"NOT FOUND"<<endl;
    }

    return 0;
}