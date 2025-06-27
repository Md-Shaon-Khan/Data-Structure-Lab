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

Node* createTree(){

   int value;
   cout<<"Enter the data(-1 for no node):";
   cin>>value;

   if(value==-1){
      return nullptr;
   }

   Node* root = createNode(value);

   cout<<"Enter left child of "<<value<<",\n";
   root->left = createTree();

   cout<<"Enter right child of "<<value<<",\n";
   root->right = createTree();

   return root;


}


void inorderTraversal(Node* root){

   if(root == nullptr){
      return;
   }

   inorderTraversal(root->left);
   cout<<root->data<<" ";
   inorderTraversal(root->right);

}

int main(){

   cout<<"Create Binary Tree:\n";
   Node* root = createTree();

   inorderTraversal(root);

}
