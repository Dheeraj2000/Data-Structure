//Delete Node then Display
//delete one node after some data

#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node *link;
}*head;//creating a global head pointer of struct type

void Display()
{
   struct node *temp=head;

    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("List has been created successfully");
}

void createnode(int n)
{
int data;
struct node *temp;

head=(struct node*)malloc(sizeof(struct node));

if(head == NULL)
{
    printf("Memory  not allocated");
    return;
}
printf("Enter first node data");
scanf("%d",&data);
temp=head;
head->data = data;
head->link = NULL;


for(int i=2;i<=n;i++)
{
    struct node *NewNode=(struct node*)malloc(sizeof(struct node));
    if(NewNode==NULL)
    {
    printf("Memory Not Allocated");
    break;
    }

    printf("Enter Node Data");
    scanf("%d",&data);
    NewNode->data=data;
    NewNode->link=NULL;

    temp->link=NewNode;

    temp=temp->link;//Moving temp node to next NewNode Location

}
}

int DeleteAtAny()
{
    struct node *temp=head;//as head is global of struct type
    
    if(head==NULL)
    {
    printf("There is no node to delete\n");
    }
    
    if(head->link==NULL)//there is only one node
    {
        free(head);
        head=NULL;
    }
    
    while(temp->link->data!=3)
    {
        temp=temp->link;
    }
    struct node *temp1=temp->link->link;
    free(temp->link);
    temp->link=temp1;
    
    return 0;
}

void main()
{
int n;
printf("Enter no of nodes");
scanf("%d",&n);

createnode(n);
DeleteAtAny();
Display();
}








