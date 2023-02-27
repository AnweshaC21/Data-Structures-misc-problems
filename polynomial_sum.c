#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int coeff;
	int exp;
	struct node *next;
} poly;
void insertterm(int,int,int);
void polyin(int);
void sort(poly*);
void polyout(poly*);
void polyadd(poly*,poly*);
poly *p1=NULL,*p2=NULL,*p3=NULL,*temp,*newnode,*nxt;

int main()
{
	int choice,n;

	printf("\nEnter input for polynomial 1 ");
	polyin(1);
	printf("\nEnter input for polynomial 2 ");
	polyin(2);
	printf("\nPolynmial 1 is : ");
	sort(p1);
	polyout(p1);
	printf("Polynmial 2 is : ");
	sort(p2);
	polyout(p2);
	polyadd(p1,p2);
	sort(p3);
	printf("\nAdded polynmial is : ");
	polyout(p3);
	
	return 0;
}
void polyin(int n)
{
	int coeff,exp;
	printf("\n(Enter coefficient 0 to be terminated)\n");
	while(1)
	{
		printf("Enter coefficent : ");
		scanf("%d",&coeff);
		if(coeff==0)
			break;
		printf("Enter exponent : ");
		scanf("%d",&exp);
		insertterm(coeff,exp,n);
	}
}
void insertterm(int co,int ex,int poly_no)
{
	newnode=(poly*)malloc(sizeof(poly));
	newnode->coeff=co;
	newnode->exp=ex;
	newnode->next=NULL;
	switch(poly_no)
	{
	case 1:
		if(p1==NULL)
		{
			p1=newnode;
			return;
		}
		temp=p1;
		break;
	case 2:
		if(p2==NULL)
		{
			p2=newnode;
			return;
		}
		temp=p2;
		break;
	case 3:
		if(p3==NULL)
		{
			p3=newnode;
			return;
		}
		temp=p3;
		break;
	}
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=newnode;
}
void sort(poly *p)
{
	int t1,t2;
	if(p==NULL)
		return;
	else
		for(temp=p;temp!=NULL;temp=temp->next)
			for(nxt=temp->next;nxt!=NULL;nxt=nxt->next)
				if(temp->exp < nxt->exp)
				{
					t1=temp->exp;
					t2=temp->coeff;
					temp->exp=nxt->exp;
					temp->coeff=nxt->coeff;
					nxt->exp=t1;
					nxt->coeff=t2;
				}
}
void polyout(poly *p)
{
	if(p==NULL)
	{
		printf("Empty List\n");
		return;
	}
	while(p!=NULL)
	{
		printf("%dx^%d ",p->coeff,p->exp);
		if(p->next!=NULL)
			printf("+ ");
		p=p->next;
	}
	printf("\n");
}
void polyadd(poly *p1,poly *p2)
{
	int r;
	while(p1!=NULL && p2!=NULL)
	{
		if(p1->exp == p2->exp)
		{
			r=p1->coeff+p2->coeff;
			if(r!=0)
				insertterm(r,p2->exp,3);
			p1=p1->next;
			p2=p2->next;
		}
		else if(p1->exp < p2->exp)
		{
			insertterm(p2->coeff,p2->exp,3);
			p2=p2->next;
		}
		else
		{
			insertterm(p1->coeff,p1->exp,3);
			p1=p1->next;
			
		}
	}
	while(p1!=NULL)
	{
		insertterm(p1->coeff,p1->exp,3);
		p1=p1->next;
	}
	while(p2!=NULL)
	{
		insertterm(p2->coeff,p2->exp,3);
		p2=p2->next;
	}	
}