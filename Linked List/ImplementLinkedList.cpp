#include<bits/stdc++.h>
using namespace std;

//Ctrl+Alt+m For Stop Executing Code in VS code
//ctrl+Alt+n for run code in vs code

class node{
 public:
 int data;
 node* next;

node(int val){
 data=val;
 next=NULL;
}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

int FindLength(node* head){
  int len=0;
  while(head != NULL){
    len++;
    head=head->next;
  }
  return len;
}

 node* reverseKGroup(node* head, int k) {
        node* prev = NULL;
        node* curr = head;
        node* firstNode = head;
        node* secNode;
        node* temp;
        int len = FindLength(head);
       
        int no_of_reverse = len/k;
     
        while(no_of_reverse){
            if( no_of_reverse != len/k ){         //First Group toh nhi hain ye waala
              secNode = curr;
            }
          int cnt=0;

            while(cnt<k){

                if(cnt!=0){
                    temp = curr->next;
                    curr->next = prev;
                    prev=curr;
                    curr=temp;
                    if(cnt==k-1 && no_of_reverse != len/k){       // Check For it is not a  first group (and)  it is  a last element of grp
                      firstNode->next=prev;
                      firstNode=secNode;;
                    }
                }

                else{
                    prev = curr;
                    curr = curr->next;
                }    

                cnt++;
            }

            if(no_of_reverse==(len/k))   //Check for first group 
            { 
                head=prev;
            }
            //firstNode->next = curr;
            --no_of_reverse;
        }
        if((len/k)==1){
          firstNode->next = curr;
          return head;
        }
        secNode->next=curr;
        //curr->next=NULL;
        return head;
    }

node* reverseListByRecursion2(node* head , node* &tail){
  if(head==NULL || head->next==NULL){
    return head;
  }
  
  node* remainList = reverseListByRecursion2(head->next,tail);
  head->next->next = head;
  head->next = NULL;
  tail=head;
  return remainList;
}

void reverseListByRecursion(node* &head,node* &tail,node* prev ,node* curr){
  if(curr==NULL){
    tail = head;
    head = prev;
    return;
  }

  node* nxt = curr->next;
  curr->next = prev;
  reverseListByRecursion(head,tail,curr,nxt);
}

void reverseList(node* &head,node* &tail){
  node* prev=NULL;
  node* curr = head;
  node* nxt = NULL;
  
  while(curr != NULL){
    if(prev==NULL){
      tail=curr;
    }
    nxt=curr->next;
    curr->next = prev;
    prev = curr;
    curr = nxt;
    // nxt = nxt->next;
  }
  head = prev;
}

void InsertAtPos(node* &head,node* &tail,int pos,int data){
  node* addNode = new node(data);
  if(pos==0){
    return;
  }
  node* curr=head;
  node* prev=NULL;
  int cnt=1;

  while(cnt < pos){
    prev=curr;
    curr=curr->next;
    cnt++;
  }


  if(curr==head){
    addNode->next=head;
    head=addNode;
    return;
  }
  prev->next = addNode;
  addNode->next = curr;

  if(curr==NULL){
    tail=addNode;
  }

}

int searchFor(node* head,int key){
  int cnt=0;
  while(head!=NULL){
    if(head->data==key){
      return cnt;
    }
    head=head->next;
    cnt++;
  }
  return -1;
}

void deleteAtPos(node* &head,node* &tail,int pos){
  int cnt=1;
  node* curr=head;
  node* prev=NULL;
  if(pos==0){
    return;
  }
  if(pos==1){
    head=curr->next;
    return;
  }

  while(cnt<pos){
    prev=curr;
    curr=curr->next;   
    cnt++;
  }
  prev->next=curr->next;
  if(tail==curr){
    tail=prev;
  }
}

void InsertAtTail(node* &head,node* &tail,int data){
   node* addNode=new node(data);
   node* temp=head;
   if(temp==NULL){
     head=addNode;
     tail=addNode;
     return;
   }
   while(temp->next!=NULL){
    temp=temp->next;
   }
   temp->next=addNode;
   tail=addNode;
}

node* InsertAtHead(node* head,node* &tail,int data){
 node *addNode=(node*)malloc(sizeof(node));
 addNode->data=data;
 addNode->next=NULL;

 node* temp=head;
 addNode->next=temp;
 head=addNode;
 
 if(temp==NULL){
  tail=addNode;
 }
 return head;
}

void printList(node* head){
 
    while(head!=NULL){

      cout<<head->data<<"\t";
      head=head->next;
    }
    cout<<endl;
}



int main(){
/*
  node* head = new node(25);
  node* secondNode = new node(50);
  node* thirdNode=new node(75);
  //head->data=23;
  head->next=secondNode;
  

  secondNode->next=thirdNode;
 // secondNode->data=56;
  
 
//Print List
printList(head);


//Insert Element At the End Of List
InsertAtTail(head,100);
printList(head);

InsertAtTail(head,125);
printList(head);

*/

node *head=NULL;
node *tail=NULL;


/*
// Insert Element At Last 
InsertAtTail(head,tail,125);
InsertAtTail(head,tail,150);
//printList(head);


//Insert Element At the First Pos
head=InsertAtHead(head,tail,100);
head=InsertAtHead(head,tail,300);
//printList(head);


//Deletion of node at perticular position
deleteAtPos(head,tail,3);
printList(head);
cout<<"tail->data = "<<tail->data<<endl;
cout<<"head->data = "<<head->data<<endl;


//Search For any element by value if not found then return -1
int key=175;
int idx = searchFor(head,key);
cout<<key<<" Found At Index "<<idx<<endl;

//Length of Linked List
int len = FindLength(head);
cout<<"Length Of List = "<<len<<endl;

InsertAtTail(head,tail,175);
cout<<"Length OF List = "<<FindLength(head)<<endl;

InsertAtPos(head,tail,1,1000);
InsertAtPos(head,tail,1,2000);
InsertAtPos(head,tail,7,3000);
InsertAtPos(head,tail,6,4000);
printList(head);
cout<<"tail->data = "<<tail->data<<endl;
cout<<"head->data = "<<head->data<<endl;
cout<<"Length OF List = "<<FindLength(head)<<endl;


//Reverse a Linked List
reverseList(head,tail);
printList(head);
cout<<"tail->data= "<<tail->data<<endl;
cout<<"head->data = "<<head->data<<endl;


//Reverse a Linked List Using Recursion
reverseListByRecursion(head,tail,NULL,head);
printList(head);
cout<<"tail->data = "<<tail->data<<endl;
cout<<"head->data = "<<head->data<<endl;


head=reverseListByRecursion2(head,tail);
printList(head);
cout<<"tail->data = "<<tail->data<<endl;
cout<<"head->data = "<<head->data<<endl;ṇ

*/


InsertAtTail(head,tail,1);
InsertAtTail(head,tail,2);
InsertAtTail(head,tail,3);
InsertAtTail(head,tail,4);
// InsertAtTail(head,tail,5);
// InsertAtTail(head,tail,6);
// InsertAtTail(head,tail,7);
// InsertAtTail(head,tail,8);
// InsertAtTail(head,tail,9);
// InsertAtTail(head,tail,96);


head=reverseKGroup(head,3);
cout<<"tail->data = "<<tail->data<<endl;
cout<<"head->data = "<<head->data<<endl;
// cout<<"aa rahe hain";
printList(head);
}