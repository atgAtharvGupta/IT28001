#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next ,*prev ;
};
typedef struct node Dnode;
Dnode* createDnode(int num)
{
    Dnode *temp;
    temp = (Dnode*)malloc(sizeof(Dnode));
    temp->data=num;
    temp->next=NULL;
    temp->prev=NULL;
return temp;
}
Dnode* insertatEnd(Dnode* head, int num)
{
    Dnode *temp=head;
    Dnode *newNode = createDnode(num);
    if(head==NULL)
        return newNode;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
return head;
}
void printDlist(Dnode* head)
{
    Dnode* temp = head;
    while(temp!=NULL)
    {
        printf("%d<->",temp->data);
        temp=temp->next;
    }
}
Dnode* findDnode(Dnode* head, int info)
{
    Dnode *temp =head;
    if(head==NULL)
        return NULL;
    while(temp!=NULL)
    {
        if(temp->data==info)
            return temp;
            temp=temp->next;
    }
    return NULL;
}
Dnode* insertBeforeDnode(Dnode* head, int num,int x)
{
    Dnode *temp=head;
    temp=findDnode(head,num);
    if(temp==NULL)
        return head;
    Dnode* newDnode = createDnode(x);
     if(head->data==num)
    {
        newDnode->next=head;
        head->prev=newDnode;
        return newDnode;
    }
    temp->prev->next=newDnode;
    newDnode->next=temp;
    newDnode->prev=temp->prev;
    temp->prev=newDnode;
return head;
}
Dnode* deleteDnode(Dnode* head,int num)
{
    Dnode *temp=head;
    temp = findDnode(head,num);
        if(temp==NULL)
        return head;
     if(head->data==num)
     {
        head->next->prev=NULL;
      return head->next;
     }
     if(temp->next==NULL)
     {
         temp->prev->next=NULL;
         return head;
     }
     temp->prev->next=temp->next;
     temp->next->prev=temp->prev;
  return head;
}
void main()
{
    Dnode* head=NULL;
    int i=0;
    for(i=0;i<9;i++)
    {
        head=insertatEnd(head,i);
    }
   head= insertBeforeDnode(head,0,100);
   head = deleteDnode(head,100);
   head = deleteDnode(head,8);
    printDlist(head);
}
