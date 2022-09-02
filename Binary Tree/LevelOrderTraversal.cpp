#include<bits/stdc++.h>
using namespace std;

class TreeNode{
 public:
 int val;
 TreeNode* left;
 TreeNode* right;

 TreeNode(int v){
  this->val = v;
  this->left = NULL;
  this->right = NULL;
 }
};

void InsertLeft(TreeNode* &root , int data){
   TreeNode* n = new TreeNode(data);
   if(root == NULL){
     root = n;
     return;
   }

   TreeNode* temp = root;
   while(temp->left){
     temp = temp->left;
   }
   temp->left = n;
}

void InsertRight(TreeNode* &root , int data){
 TreeNode* n = new TreeNode(data);
 if(root == NULL){
  root = n;
  return;
 }

 TreeNode* temp = root;
 while(temp->right){
  temp = temp->right;
 }
 temp->right = n;
}

void PrintTree(TreeNode* root){
 if(root == NULL){
  // cout<<"null  ";
  return;
 }

 PrintTree(root->left);
 cout<<root->val<<"  ";          //5  4  3  2  1  
 PrintTree(root->right);
}

void PrintLevelOrder(TreeNode* root){
 queue<TreeNode*>q;
 q.push(root);
 q.push(NULL);
 int sum = 0;
 int cnt = 0;
 int i = 1;
 while(!q.empty()){
  TreeNode* temp = q.front();
  q.pop();
  
  if(temp == NULL){

     if(!q.empty()){
      int avg = sum/cnt;
      cout<<"Average At Level "<<i<<" = "<<avg<<"\t\t";
      cnt = 0;
      sum = 0;
      i++;
      q.push(NULL);
     }
     else{
      //Last Level when temp==NULL but q is empty bcoz of q.pop at (65)
      int avg = sum/cnt;
      cout<<"Average At Level "<<i<<" = "<<avg;
     }
  }
  else{
   cnt++;
   sum+=temp->val;
   //cout<<temp->val<<"  ";
   if(temp->left){
    q.push(temp->left);
   }
   if(temp->right){
    q.push(temp->right);
   }
  }
 }
}


int main(){
 TreeNode* root = new TreeNode(1);
 InsertLeft(root,2);
 InsertRight(root,9);
 InsertLeft(root->left,3);
 InsertLeft(root->right,4);
 InsertRight(root->right,8);
 InsertLeft(root->right,5);
 InsertRight(root->left,7);
 
// PrintTree(root);
 // cout<<endl<<root->right->right->val;
 PrintLevelOrder(root);
}