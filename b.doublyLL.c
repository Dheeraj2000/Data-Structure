//Doubly Link List

#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node *prev;
struct node *next;
}*head;

//Insertion at begin
void InsertBegin(int item)
{
struct node *temp=(struct node*)malloc(sizeof(struct node));
temp->next=head;
temp->data=item;
head=temp;
temp->prev=NULL;
head->next->prev=head;
}


void InsertEnd(int item)
{
struct node *NewNode=(struct node*)malloc(sizeof(struct node));  //Create Node at any Random location
struct node *temp;
temp=head;
while(temp->next!=NULL)
{
    temp=temp->next; //go to Last Node
}
NewNode->data=item;
temp->next=NewNode;
NewNode->prev=temp;
NewNode->next=NULL;
}


void InsertAny(int item)
{
struct node *temp;
struct node *NewNode=(struct node*)malloc(sizeof(struct node));  //Create Node at any Random location
temp=head;
while(temp->data!=2)
{
    temp=temp->next;
}
NewNode->data=item;
NewNode->prev=temp;
NewNode->next=temp->next;
temp->next->prev=NewNode;
temp->next=NewNode;
}


void DeleteAtBegin()
{
    head=head->next;
    free(head->prev);
    head->prev=NULL;
}


void DeleteAtEnd()
{
    struct node *temp;
    temp=head;

    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }

    free(temp->next);
    temp->next=NULL;

}


void DeleteAtAny()
{
    struct node *temp;
    temp=head;

    while (temp->data!=3)
    {
        temp=temp->next;
    }
    struct node *temp1;
    temp1=temp;
    
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp1);
    
}


//Creation of node
void createnode(int n)
{
    
    int data;
    head=(struct node*)malloc(sizeof(struct node));
    struct node *temp;
    if(head == NULL)
    {
        printf("Memory  not allocated");
        return 0;
    }
    printf("Enter first node data");
    scanf("%d",&data);
    temp=head;
    head->data = data;
    head->next = NULL;
    head->prev = NULL;


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
        NewNode->data=data; //filling data
        NewNode->prev=temp; //link Newnode to prev
        NewNode->next=NULL; //filing Newnode next part to NULL
        temp->next=NewNode; // changing prev node next part from NULL to some link
        temp=temp->next;
    }

}

void traversing()
{
    struct node *temp;
    temp=head;

    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\nList has been created successfully\n");
}

void traversing1()
{
    struct node *temp;
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->prev;
    }
    printf("\nList has been created successfully\n");
}


void main()
{

    int n;
    printf("Enter no of nodes");
    scanf("%d",&n);

    createnode(n);
    traversing();
    DeleteAtAny();
    traversing();

}
