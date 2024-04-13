#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node Node;
Node* createNode(int num)
{
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = num;
    temp->next = NULL;
return temp;
}
Node* insertatBeggining(Node* head, int num)
{
    Node* temp = createNode(num);
    temp->next=head;
    printf("%d ",num);
return temp;
}
void printList(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        printf("%d->",temp->data);
        temp = temp->next;
    }
}
Node* deleteatBeggining(Node* head)
{
    Node* temp = head;
     head = temp->next;
     free(temp);
    //temp->next = NULL;
    return head;
}
Node* deleteNode(Node* head ,int n)
{
    Node* temp =head ;
    if(head==NULL)
        return NULL;

    if(head->data==n)
        return head->next;
    while(temp->next != NULL)
    {
        if(n==temp->next->data)
        {

            temp->next=temp->next->next;
            break;
        }
        temp=temp->next;
    }
    return head;
}
int getLength(Node* head)
{
    int count=0;
    Node* temp=head;
    while(temp!=NULL)
    {
        count=count+1;
        temp=temp->next;
    }
    return count;
}
Node* getpreviousNode(Node* head, int x)
{
    Node* temp = head;
    while(temp->next->data != x)
    {
        temp=temp->next;
    }
    return temp;
}
Node* insertBeforeNode(Node* head , int num,int dat)
{
  Node* temp;
 Node* newnode = createNode(dat);
 if(head->data==num)
 {
     newnode->next=head;
     newnode->data=dat;
     return newnode;
 }
  temp=getpreviousNode(head,num) ;
  newnode->next = temp->next;
  //flag->data=dat;
  temp->next = newnode;
  return head;
}
int main()
{
    Node* head=NULL;
    Node* head2 = NULL;
    int i;
    for(i=0;i<1000000000;i++)
    {
        head = insertatBeggining(head,i);
       // head2 = insertatBeggining(head2,i+100);
    }
    head= deleteNode(head,10);

   // head2=deleteatBeggining(head2);
    int k=getLength(head);
  // head= insertBeforeNode(head,9,100);
//printf("\n%d",k);
   // printList(head2);
   printList(head);
    return 0;
}
