#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int coeff;
    int exp;
    struct node *next;
} poly;
poly *p1=NULL,*p2=NULL,*p3=NULL,*temp,*newnode,*i,*j;

void insertterm(int,int,int);
void polyin(int);
void sort(poly*);
void polyout(poly*);
void polymul(poly*,poly*);

int main()
{
	int choice,n;
	printf("\nInput polynomial 1");
	polyin(1);
	printf("\nInput polynomial 2");
	polyin(2);
	printf("\nPolynmial 1 is : ");
	sort(p1);
	polyout(p1);
	printf("Polynmial 2 is : ");
	sort(p2);
	polyout(p2);
	polymul(p1,p2);
	printf("\nMultiplied polynmial is : ");
	sort(p3);
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
			for(j=temp->next;j!=NULL;j=j->next)
				if(temp->exp < j->exp)
				{
					t1=temp->exp;
					t2=temp->coeff;
					temp->exp=j->exp;
					temp->coeff=j->coeff;
					j->exp=t1;
					j->coeff=t2;
				}
}
void polyout(poly *p)
{
	if(p==NULL)
	{
		printf("Empty\n");
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
void polymul(poly *p1,poly *p2)
{
    int c,e,flag;
    for(i=p1;i!=NULL;i=i->next)
        for(j=p2;j!=NULL;j=j->next)
        {
            flag=0;
            c=i->coeff*j->coeff;
            e=i->exp+j->exp;
            temp=p3;
            while(temp!=NULL)
            {
                if(e==temp->exp)
                {
                    temp->coeff+=c;
                    flag++;
                    break;
                }
                temp=temp->next;
            }
            if(flag==0)
                insertterm(c,e,3);
        }
}