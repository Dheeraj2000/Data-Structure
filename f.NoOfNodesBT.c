/*This file contains 4 functions
********************************************
Number of Nodes in Binary Tree
********************************************
*/


#include <stdio.h>
#include<stdlib.h>

//Create node
typedef struct node
    {

        int data;
        struct node *left;
        struct node *right;

    }Node;//Making Node as global


//Creating node for tree //
struct node *CreateTree()
{
    
    
    int Nodedata;
    Node *newnode=(Node*)malloc(sizeof(Node)); //dynamically allocate memory to Node

    printf("Enter the data for the nodes(0 for no data)");
    scanf("%d",&Nodedata);

    if(Nodedata==0)
    {
        return NULL; 
    }

      newnode->data=Nodedata;

      printf("Enter the left child data rooted at %d \n",newnode->data);

      newnode->left=CreateTree();

      printf("Enter the right child data rooted at %d\n",newnode->data);

      newnode->right=CreateTree();

      return newnode;
}

int Count(Node *t)
{
    if(t==NULL)
    {
        return 0;
    }
    else
    {
        return 1+Count(t->left)+Count(t->right);
    }
    
}

void traverse(Node *t)
{

    if(t!=NULL)
    {

        printf("Left child data is %d ",t->data);
        traverse(t->left);
        t=t->right;
    
    }

   if(t!=NULL)
    {
       printf("Right child data is %d\n",t->data);
       traverse(t->right);
    }

}




int main()
{
    Node *root=CreateTree(); //final return root from function CreateTree
    Node *t=root;   //assign root node to another node t


    printf("\n");
    printf("%d",Count(t));

    return 1;

}
