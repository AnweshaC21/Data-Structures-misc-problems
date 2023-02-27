#include<stdio.h>
#include<stdlib.h>

struct node
{
    int value;
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
	int val;
	printf("Enter the value to be inserted : ");
	scanf("%d",&val);
	ptr=(struct node*)malloc(sizeof(struct node));
    ptr->value=val;
    ptr->next=NULL;
    if(front==NULL)
        front=ptr;
    else
        rear->next=ptr;
    rear=ptr;
    rear->next=front;
}

void remove_element()
{
	if(front==NULL)
		printf("UNDERFLOW\n");
	else 
	{
        if(front==rear)
        {
            ptr=front;
            front=NULL;
            rear=NULL;
        }
        else
        {
            ptr=front;
            front=ptr->next;
            rear->next=front;
        }
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
		printf("\nThe circular queue is : \n");
		for(ptr=front;ptr->next!=front;ptr=ptr->next)
        	printf("%d\t",ptr->value);
       	printf("%d\t",ptr->value);
	}
}