#include <stdio.h>
#include <stdlib.h>

  struct node {
        int data;
        struct node *prev;
        struct node *next;
  };

  struct node *Front = NULL, *Rear = NULL; //initially

  struct node *createNode(int data) {
        struct node *newnode = (struct node *)malloc(sizeof (struct node));
        newnode->data = data;
        newnode->next = newnode->prev = NULL;
        return (newnode);
  }

   /*
    * create sentinel(dummy head & tail) that
    * helps us to do insertion and deletion 
    * operation at front and rear so easily.  And
    * these dummy head and tail wont get deleted
    * till the end of execution of this program
    */

  void createSentinels() {
        Front = createNode(0);
        Rear = createNode(0);
        Front->next = Rear;
        Rear->prev = Front;
  }

  /* insertion at the front of the queue */
  void enqueueAtFront(int data) {
        struct node *newnode, *temp;
        newnode = createNode(data);
        temp = Front->next;
        Front->next = newnode;
        newnode->prev = Front;
        newnode->next = temp;
        temp->prev = newnode;
  }

  /*insertion at the rear of the queue *///
  void enqueueAtRear(int data) {
        struct node *newnode, *temp;
        newnode = createNode(data);
        temp = Rear->prev;
        Rear->prev = newnode;
        newnode->next = Rear;
        newnode->prev = temp;
        temp->next = newnode;
  }

  /* deletion at the front of the queue */
  void dequeueAtFront() {
        struct node *temp;
        if (Front->next == Rear) {
                printf("Queue is empty\n");
        } else {
                temp = Front->next;
                Front->next = temp->next;
                temp->next->prev = Front;
                free(temp);
        }
        return;
  }


  /* deletion at the rear of the queue */////

  void dequeueAtRear()  {
        struct node *temp;
        if (Rear->prev == Front) {
                printf("Queue is empty\n");
        } else {
                temp = Rear->prev;
                Rear->prev = temp->prev;
                temp->prev->next = Rear;
                free(temp);
        }
        return;
  }

  /* display elements present in the queue */
  void display() {
        struct node *temp;

        if (Front->next == Rear) {
                printf("Queue is empty\n");
                return;
        }

        temp = Front->next;
        while (temp != Rear) {
                printf("%d ", temp->data);
                temp = temp->next;
        }
        printf("\n");
  }

  int main() {
        int data, ch;
        createSentinels();
        while (1) {
                printf("1. Enqueue at front\n2. Enqueue at rear\n");
                printf("3. Dequeue at front\n4. Dequeue at rear\n");
                printf("5. Display\n6. Exit\n");
                printf("Enter your choice:");
                scanf("%d", &ch);
                switch (ch) {
                        case 1:
                                printf("Enter the data to insert:");
                                scanf("%d", &data);
                                enqueueAtFront(data);
                                break;

                        case 2:
                                printf("Enter ur data to insert:");
                                scanf("%d", &data);
                                enqueueAtRear(data);
                                break;

                        case 3:
                                dequeueAtFront();
                                break;

                        case 4:
                                dequeueAtRear();
                                break;

                        case 5:
                                display();
                                break;

                        case 6:
                                exit(0);

                        default:
                                printf("Pls. enter correct option\n");
                                break;
                }
        }
        return 0;
  }