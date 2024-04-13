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
return temp;
}
void printList(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {   printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
Node* deleteatBeggining(Node* head)
{
    Node* temp = head;
    head = temp->next;
    free(temp);
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
  temp->next = newnode;
  return head;
}
Node* binarytoOctal(Node* head)
{
    Node* temp=head;
    int len = getLength(head);
    int rem = len % 3;
    if ( rem == 1)
    {
        temp = temp->next;
    }
    if ( rem == 2)
    {
        int info= temp->data *2 + temp->next->data;
        temp->data = info;
        temp->next=temp->next->next;
        temp=temp->next;
    }
    while (temp!=NULL)
    {
       int info= temp->data *4 + temp->next->data*2 +temp->next->next->data;
       temp->data = info;
       temp->next=temp->next->next->next;
       temp=temp->next;
    }
return head;
}
int main()
{
    Node* head=NULL;
    Node* head2 = NULL;
    int i;
    for(i=0;i<100;i++)
    {
        head = insertatBeggining(head,rand()%2);
    }
    int k=getLength(head);
    printList(head);
    head = binarytoOctal(head);
    printList(head);
    printf("Number of Nodes in list are: %d",k);
    return 0;
}
