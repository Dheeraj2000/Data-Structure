#include<stdio.h> 
#include<stdlib.h> 

/* A binary tree tNode has data, pointer to left child 
and a pointer to right child */
struct node
    {

        int data;
        struct node *left;
        struct node *right;

    };
	
/* Structure of a stack node. Linked List implementation is used for 
stack. A stack node contains a pointer to tree node and a pointer to 
next stack node */
struct sNode 
{ 
struct node *w; 
struct sNode *next; 
}; 

/* Stack related functions */
void push(struct sNode **top_ref, struct node *w); 
struct node *pop(struct sNode **top_ref); 
int isEmpty(struct sNode *top); 

/* Iterative function for inorder tree traversal */
void inOrder(struct node *root) 
{ 
/* set current to root of binary tree */
struct node *current = root; 
struct sNode *s = NULL; /* Initialize stack s */
int done = 0; 

while (!done) 
{ 
	/* Reach the left most tNode of the current tNode */
	if(current != NULL) 
	{ 
	/* place pointer to a tree node on the stack before traversing 
		the node's left subtree */
	push(&s, current);											 
	current = current->left; 
	} 
		
	/* backtrack from the empty subtree and visit the tNode 
	at the top of the stack; however, if the stack is empty, 
	you are done */
	else															
	{ 
	if (!isEmpty(s)) 
	{ 
		current = pop(&s); 
		printf("%d ", current->data); 

		/* we have visited the node and its left subtree. 
		Now, it's right subtree's turn */
		current = current->right; 
	} 
	else
		done = 1; 
	} 
} /* end of while */
}	 

/* Function to push an item to sNode*/
void push(struct sNode **top_ref, struct node *w) 
{ 
/* allocate tNode */
struct sNode *new_tNode=(struct sNode*) malloc(sizeof(struct sNode)); 

if(new_tNode == NULL) 
{ 
	printf("Stack Overflow \n"); 
	getchar(); 
	exit(0); 
}			 

/* put in the data */
new_tNode->w = w; 

/* link the old list off the new tNode */
new_tNode->next = (*top_ref); 

/* move the head to point to the new tNode */
(*top_ref) = new_tNode; 
} 

/* The function returns true if stack is empty, otherwise false */
int isEmpty(struct sNode *top) 
{ 
return (top == NULL)? 1 : 0; 
} 

/* Function to pop an item from stack*/
struct node *pop(struct sNode **top_ref) 
{ 
struct node *res; 
struct sNode *top; 

/*If sNode is empty then error */
if(isEmpty(*top_ref)) 
{ 
	printf("Stack Underflow \n"); 
	getchar(); 
	exit(0); 
} 
else
{ 
	top = *top_ref; 
	res = top->w; 
	*top_ref = top->next; 
	free(top); 
	return res; 
} 
} 


//Creating node for tree 
struct node *CreateTree()
{
    
    
    int Nodedata;
    struct node *newnode=(struct node*)malloc(sizeof(struct node)); //dynamically allocate memory to Node

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


int main() 
{ 


struct node *root=CreateTree(); //final return root from function CreateTree
struct node *t=root;   //assign root node to another node t


inOrder(t); 

return 1; 
} 
