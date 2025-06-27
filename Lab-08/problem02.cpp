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
   if(value>root->data){

      root->right = insertionTree(root->right,value);

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
   Node* root = nullptr;
   cout<<"Enter how many nodes want to insert: ";
   cin>>n;

   for(int i=1;i<=n;i++){

      cin>>value;
      root = insertionTree(root,value);

   }

   cout<<endl;
   inorderTraversal(root);

   return 0;

}
