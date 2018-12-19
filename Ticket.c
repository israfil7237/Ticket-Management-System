#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct person                            //Define a structure for creating a node in the queue
{
    char name[30];
    char phone[20];
    struct person *next;
};
struct person *front=NULL,*rear=NULL,*k;    //globally declared structure variable,front and rear pointing to the NULL

void enqueue(int n)                   //enqueue function holds an integer value as a parameter that say how many nodes user want to entered in the queue
{
    int i;
    for(i=0; i<n; i++)
    {
        if (rear == NULL) //IF rear pointing to NULL then create a 1st node for the queue
        {
            rear = (struct person *)malloc(sizeof(struct person)); //it creates dynamic memory for the person data type
            printf("\nEnter the Person Name: ");
            scanf("%s",rear->name);                 //assigning the person name and phone number here
            printf("\nEnter the Phone Number: ");
            scanf("%s",rear->phone);
            front=rear;              //after create 1st node.Now front and rear both are pointing to the 1st node

        }
        else    //IF rear pointer don't point to the NULL then creates a new node this way
        {
            k=(struct person *)malloc(sizeof(struct person));
            printf("\nEnter the Person Name: ");
            scanf("%s",k->name);                  //assigning the person name and phone number here
            printf("\nEnter the Phone Number: ");
            scanf("%s",k->phone);
            k->next=NULL;         //Last node always pointing to NULL
            rear->next=k;
            rear=k;
        }

    }
}


void display()
{
    struct person *t;
    t=front;
    if(t==NULL){
        printf("\n\n\n Queue is empty!!!!!\n\n\n");
        return;
    }
    while(t!=NULL)  //printing all the nodes until t is not equal NULL
    {
        printf("\n  Person Name  : %s ",t->name);
        printf("\nPerson Phone N0: %s ",t->phone);
        printf("\n\n");
        t=t->next;
    }
}
void dequeue()
{
    struct person *temp;

    temp = front;

    if (temp == NULL)         //If queue is NULL then show the queue is empty
    {
        printf("\n\n\n Queue is empty!!!!!\n\n\n");
        return;
    }
    else
    {

        if (temp->next != NULL)  //if queue is not pointing to NULL then remove the front node
        {
            temp = temp->next;
            printf("\n\n Frontier person %s is removed\n\n",front->name);

            free(front);
           front = temp;
       }
        else
        {
            printf("\n\n Frontier person %s is removed\n\n",front->name);
            free(front);
            front = NULL;
            rear = NULL;
        }
    }
}

int main()
{
    int n,c;
    while(c!=0)
    {
        printf("\n\tOPTION\n");
        printf("\nEnter 1 for Creating the QUEUE\n");
        printf("\nEnter 2 for Displaying the Record\n");
        printf("\nEnter 3 for Deleting a Record\n");
        printf("\nEnter 0 for Exit!\n");
        printf("\nEnter the choice:");
        scanf("%d",&c);        //user choice the option for Adding,Deleting and See the record from the queue
        switch(c)
        {
        case 1:     //case 1 for enqueue the data in the queue
            printf("\nEnter the maximum size of the QUEUE:");
            scanf("%d",&n);     //this line Wants to know how many person in the queue
            enqueue(n);        //enqueue function passing an argument
            break;
        case 2:               //case 2 for display the record
            display();
            break;
        case 3:               //case 3 delete the record
            dequeue();
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("\nEntered a Wrong Choice!!!!!!!!!!");
        }
    }

    return 0;
}

