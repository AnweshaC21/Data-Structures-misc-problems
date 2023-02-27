#include<stdio.h>
#include<stdlib.h>

struct node
{
    int value;
    int priority;
    struct node *next;
};
struct node *front,*rear,*ptr,*temp;

void insert_element();
void remove_element();
void display();

int main()
{
    int ch,n;
	while(1)
	{
		printf("\nMENU");
		printf("\n1. Insert");
		printf("\n2. Remove");
		printf("\n3. Display");
		printf("\n4. Exit");
		printf("\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert_element();
				break;
			case 2:
				remove_element();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(1);
			default:
				printf("WRONG INPUT\n");
		}
	}
}

void insert_element()
{
	int val,pr;
	printf("Enter the value to be inserted : ");
	scanf("%d",&val);
    printf("Enter its priority : ");
    scanf("%d",&pr);
	ptr=(struct node*)malloc(sizeof(struct node));
    ptr->value=val;
    ptr->priority=pr;
    ptr->next=NULL;
    if(front==NULL || pr<front->priority)
    {
        ptr->next=front;
        front=ptr;
    }
    else
    {
        while(front->next!=NULL && front->next->priority<=pr)
            front=front->next;
        ptr->next=front->next;
        front->next=ptr;
    }
}

void remove_element()
{
	if(front==NULL)
		printf("UNDERFLOW\n");
	else
	{
		ptr=front;
		front=ptr->next;
		printf("Removed element is : %d",ptr->value);
		free(ptr);
		printf("\n");
	}
}

void display()
{
	if(front==NULL)
		printf("QUEUE EMPTY\n");
	else
	{
		printf("\nThe priority queue is : \n");
		for(ptr=front;ptr!=NULL;ptr=ptr->next)
			printf("%d (%d)\t",ptr->value,ptr->priority);
	}
}