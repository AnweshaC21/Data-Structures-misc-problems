#include<stdio.h>
#include<stdlib.h>

struct node
{
    int value;
    struct node *next;
};
struct node *top=NULL,*ptr,*temp;

void push();
void pop();
void display();

int main()
{
    int ch,n;
	while(1)
	{
		printf("\nMENU");
		printf("\n1. Push");
		printf("\n2. Pop");
		printf("\n3. Pop & Display Stack");
		printf("\n4. Exit");
		printf("\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
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
void push()
{
	int val;
	printf("Enter the value to be pushed : ");
	scanf("%d",&val);
	ptr=malloc(sizeof(struct node));
	ptr->value=val;
	ptr->next=NULL;
	temp=top;
	top=ptr;
	top->next=temp;
}
void pop()
{
	if(top==NULL)
		printf("STACK UNDERFLOW\n");
	else
	{
		ptr=top;
		top=ptr->next;
		printf("Popped element is : %d",ptr->value);
		free(ptr);
		printf("\n");
	}
}
void display()
{
	if(top==NULL)
		printf("STACK UNDERFLOW\n");
	else
	{
		printf("\nElements of stack : \n");
		while(top!=NULL)
			pop();
	}
}