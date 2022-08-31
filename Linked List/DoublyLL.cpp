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

 ~node(){
  int val=this->data;
  if(this->next != NULL){
     delete next;
     this->prev=NULL;
  }
  cout<<val<<" is deleted from List"<<endl;
 }
};

void InsertAtPos(node* &head,node* &tail,int pos,int val){
 node* n=new node(val);
 if(pos==1){
  node* temp=head;
  n->next=temp;
  head=n;
  return;
 }
 int cnt=1;
 node* prv=NULL;
 node* curr=head;
 while(cnt<pos){
    prv=curr;
    curr=curr->next;
    cnt++;
 }
 if(curr==NULL){
    prv->next = n;
    tail=n;
    return;
 }
 prv->next = n;
 n->prev = prv;
 n->next = curr;
 curr->prev=n;
}

void deleteFromList(node* &head,node* &tail,int pos){
 if(pos==1){
  node* temp=head;
  head=head->next;
  temp->next=NULL;
  delete temp;
  return;
 }
int cnt=1;
node* prv=NULL;
node* curr=head;
while(cnt<pos){
  prv=curr;
  curr=curr->next;
  cnt++;
}
if(curr->next==NULL){     //Delete Last Element
  prv->next=curr->next;
  tail=prv;
  delete curr;
  return;
}
prv->next=curr->next;
curr->next->prev=prv;
curr->prev=NULL;
curr->next=NULL;
delete curr;
}

void InsertAtTail(node* head,node* &tail,int val){
  if(head==NULL){
     // InsertAtHead(head,tail,val);
     node* n=new node(val);
     head=n;
     tail=n;
     return;
  }
  
  node* n=new node(val);
  node* temp=tail;
  temp->next=n;
  n->prev=temp;
  n->next=NULL;
  tail=n;
}

void InsertAtHead(node* &head,node* &tail,int val){
 node* n=new node(val);
 if(head==NULL){     //If List Is Empty
   head=n;
   tail=n;
   return;
 }
  
 node* temp=head;
 n->next=temp;
 head=n;
}

void printList(node* head){
 node* temp=head;
 while(temp!= NULL){
     cout<<temp->data<<" ";
     temp=temp->next;
 }
 cout<<endl;
}

int main(){
 node* head = NULL;
 node* tail=NULL;

//Insert Element at first
 InsertAtHead(head,tail,100);
 InsertAtHead(head,tail,200);
 InsertAtHead(head,tail,300);
 InsertAtHead(head,tail,400);
 InsertAtHead(head,tail,500);
 printList(head);
 cout<<"Tail is "<<tail->data<<endl;
 cout<<"head is "<<head->data<<endl;

//Insert Element at last pos
 InsertAtTail(head,tail,600);
 InsertAtTail(head,tail,700);
 printList(head);
 cout<<"Tail is "<<tail->data<<endl;
 cout<<"head is "<<head->data<<endl;


//Insert element at any position 
 InsertAtPos(head,tail,7,450);
 printList(head);
  cout<<"Tail is "<<tail->data<<endl;
 cout<<"head is "<<head->data<<endl;

//Delete Element by position 

 deleteFromList(head,tail,8);
 printList(head);
 cout<<"Tail is "<<tail->data<<endl;
 cout<<"head is "<<head->data<<endl;


}