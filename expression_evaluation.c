#include<stdio.h>
#include<math.h>
#define size 20

char stack[size],infix[size],postfix[size];
int Ostack[size],top=0;

char pop(char[]);
void push(char[],char);
int popint(int[]);
void pushint(int[],int);
int InStackPriority(char);
int InComingPriority(char);
void conv_postfix(char[]);
void evaluation(char[]);

void main()
{
	stack[0]='\0';
	printf("Enter infix expression : ");
	scanf("%s",&infix);
	conv_postfix(infix);
	printf("Postfix expression : %s",postfix);
	evaluation(postfix);
	printf("\nResult : %d",Ostack[top]);
}
int InStackPriority(char op)
{
	switch(op)
	{
	case '(':
		return 0;
	case '+':
		return 1;
	case '-':
		return 1;
	case '*':
		return 2;
	case '/':
		return 2;
	case '%':
		return 2;
	case '^':
		return 3;
	default:
		return -1;
	}
}
int InComingPriority(char op)
{
	switch(op)
	{
	case '(':
		return 4;
	case '+':
		return 1;
	case '-':
		return 1;
	case '*':
		return 2;
	case '/':
		return 2;
	case '%':
		return 2;
	case '^':
		return 3;
	default:
		return -1;
	}
}
void push(char stack[],char val)
{
	if(top==size-1)
		printf("Stack Overflow");
	else
		stack[++top]=val;
}
void pushint(int stack[],int val)
{
	if(top==size-1)
		printf("Stack Overflow");
	else
		stack[++top]=val;
}
char pop(char stack[])
{

	if(top==0)
		printf("Stack Underflow");
	return (stack[top--]);
}
int popint(int stack[])
{

	if(top==0)
		printf("Stack Underflow");
	return (stack[top--]);
}
void conv_postfix(char in[])
{
	int i=0,j=0;
	while(1)
	{
		if(in[i]=='\0')
		{
			while(top>0)
				postfix[j++]=pop(stack);
			postfix[j]='\0';
			return;
		}
		else if(in[i]==')')
		{
			while(stack[top]!='(')
				postfix[j++]=pop(stack);
			top--;
		}
		else if(in[i]>='0' && in[i]<='9')
			postfix[j++]=in[i];
		else
		{
			while(InStackPriority(stack[top])>=InComingPriority(in[i]))
				postfix[j++]=pop(stack);
			push(stack,in[i]);
		}
	i++;
	}
}
void evaluation(char E[])
{
	int i=0,op,operand1,operand2;
	top=0;
	while(E[i]!='\0')
	{
		if(E[i]>='0' && E[i]<='9')
		{
			op=(int)E[i]-48;
			pushint(Ostack,op);
		}
		else
		{
			operand1=popint(Ostack);
			operand2=popint(Ostack);
			switch(E[i])
			{
			case '+':
				operand2=operand2+operand1;
				break;
			case '-':
				operand2=operand2-operand1;
				break;
			case '*':
				operand2=operand2*operand1;
				break;
			case '/':
				operand2=operand2/operand1;
				break;
			case '%':
				operand2=operand2%operand1;
				break;
			case '^':
				operand2=pow(operand2,operand1);
				break;
			}
			pushint(Ostack,operand2);
		}
		i++;
	}
}