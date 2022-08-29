#include<stdio.h>
#include<stdlib.h>

struct node{
 int data;
 struct node *next;
};

void main(){
 struct node *n1=(struct node*)malloc(sizeof(struct node));
 struct node *n2=(struct node*)malloc(sizeof(struct node));
 n1->data=12;
 n1->next=n2;
 n2->next=NULL;
 n2->data=34;
 printf("%d\t",n1->data);
 printf("%d\t",n2->data);

}