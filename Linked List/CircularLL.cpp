#include<bits/stdc++.h>
using namespace std;

class node{
  public:
  int data;
  node* next;

  node(int val){
     this->data = val;
     this->next = NULL;
  }
};

void deleteFromList(node* &head , node* &tail , int key){
 node* prev = NULL;
 node* curr = head;
 while(curr->data != key){
  prev = curr;
  curr = curr->next;
  if(curr==head){
   cout<<"Key Not Found !!";
  }
 }
 
 node* curr
}

void InsertAtTail(node* &head , node* &tail , int val){
   node* n = new node(val);
   if(head == NULL){
    n->next = n;
    head = n;
    tail = n;
    return;
   }
   
   // node* temp = tail;
   // n->next = temp->next;
   // temp->next = n;
   node* temp = head;   //If Tail Is not passed
   while(temp->next != head){
    temp = temp->next;
   }
   temp->next = n;
   n->next = head;
   tail = n;
}

void InsertAtHead(node* &head , node* &tail , int val){
  node* n = new node(val);
  if(head==NULL){
   n->next=n;
   head = n;
   tail = n;
   return;
  }
  node* temp = head;
  while(temp->next != head){
   temp = temp->next;
  }
  n->next = head;
  temp->next = n;
  head = n;
}

void printList(node* head){
 node* temp = head;
 do{
  cout<<temp->data<<"  ";
  temp = temp->next;
 }while(temp != head);
 cout<<endl;
}

void InsertAtPos(node* &head , node* &tail , int pos , int val){
 node* n = new node(val);
 if(pos==1){
    InsertAtHead(head,tail,val);
    return;
 }
 node* prev = NULL;
 node* curr= head;
 int cnt=1;
 while(cnt<pos){
   prev = curr;
   curr = curr->next;
   cnt++;
 }
 if(curr == head){
  InsertAtTail(head,tail,val);
  return;
 }
 prev->next = n;
 n->next = curr;
}

int main(){
  node* head=NULL;
  node* tail=NULL;


//Insert Element At First Position
  InsertAtHead(head,tail,100);
  InsertAtHead(head,tail,200);
  InsertAtHead(head,tail,300);
  InsertAtHead(head,tail,400);
  printList(head);
  cout<<"Value of Head is "<<head->data<<endl;
  cout<<"Value of Tail is "<<tail->data<<endl;


//Insert Element At Last Position
InsertAtTail(head,tail,500);
InsertAtTail(head,tail,600);
InsertAtTail(head,tail,700);
printList(head);
cout<<"Value of Head is "<<head->data<<endl;
cout<<"Value of Tail is "<<tail->data<<endl;

//Insert Element At Position
InsertAtPos(head,tail,8,150);
printList(head);
cout<<"Value of Head is "<<head->data<<endl;
cout<<"Value of Tail is "<<tail->data<<endl;


//Delete From A List By Value
deleteFromList(head,tail,150);
}