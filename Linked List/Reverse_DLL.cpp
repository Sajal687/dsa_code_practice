#include<bits/stdc++.h>
using namespace std;

class node{
 public:
 int data;
 node* next;
 node* prev;
 
 node(int val){
   this->data=val;
   this->next=NULL;
   this->prev=NULL;
 }
};


void InsertAtTail(node* &head,node* &tail,int val){
   node* n=new node(val);
   if(head==NULL){
    head=n;
    tail=n;
    return;
   }
   node* temp=tail;
   temp->next = n;
   n->prev = temp;
   tail = n;
}

void printList(node* head){
  node* temp=head;
  while(temp!=NULL){
   cout<<temp->data<<" ";
   temp=temp->next;
  }
  cout<<endl;
}

void ReverseList(node* &head, node* &tail){
 node* curr = head;
 while(curr != NULL){
 // cout<<curr->data<<"\t";
 node* temp = curr->prev;
 curr->prev = curr->next;
 curr->next = temp;
 curr = curr->prev;
}
node* temp = head;
head = tail;
tail = temp;
}

int main(){
   node* head=NULL;
   node* tail=NULL;
   
   InsertAtTail(head,tail,100);
   InsertAtTail(head,tail,200);
   InsertAtTail(head,tail,300);
   InsertAtTail(head,tail,400);
   InsertAtTail(head,tail,500);

   printList(head);

   ReverseList(head,tail);
   printList(head);
   cout<<"Value Of Head is "<<head->data<<endl;
   cout<<"Value Of tail is "<<tail->data<<endl;
  
 /*      /////  Output ////////
100 200 300 400 500 
500 400 300 200 100 
Value Of Head is 500
Value Of tail is 100
*/


}