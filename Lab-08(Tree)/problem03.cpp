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
Node* searchTree(Node* root,int key){

   if(root==nullptr || root->data==key){

      return root;

   }

   if(key<root->data){

      return searchTree(root->left,key);

   }
   if(key>root->data){

      return searchTree(root->right,key);

   }

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

   Node* root = nullptr;
   int n,value;
   cout<<"How many nodes:";
   cin>>n;

   cout<<"Enter the nodes:";
   for(int i=1;i<=n;i++){
    cin>>value;
    root = insertionTree(root,value);
   }

   cout<<"After inserting:";
   inorderTraversal(root);

   cout<<endl;
   int key;
   cout<<"Enter the search key:";
   cin>>key;

   Node* found = searchTree(root,key);

   if(found != nullptr){
    cout<<"FOUND"<<endl;
   }
   else{
    cout<<"NOT FOUND"<<endl;
   }

   return 0;

}
