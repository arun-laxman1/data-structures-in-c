#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define MAXI 200

typedef char ele;

typedef struct{
	ele *data;
	int top;
	int max;
}mystack;
typedef mystack* stack;

int create()
{
	stack s=(stack)malloc(sizeof(mystack));
	s->max=MAXI;
	s->data=(ele*)malloc(sizeof(ele)*s->max);
	s->top=-1;
	return s;
}

int isFull(stack s)
{
	return s->top==s->max-1;
}

int isEmpty(stack s)
{
	return s->top==-1;
}

int push(stack s,ele p)
{
	if(isFull(s))
		return;
	s->data[s->top+1]=p;
	s->top+=1;
	return 1;
}

stack pop(stack s)
{
	if(isEmpty(s))
		return;
	return s->data[s->top--];
}

int display(stack s)
{ 
	int i;
    for(i=s->top;i>=0;i--)
    {
    	printf("%c\n",s->data[i]);	
	}
	return 1;
}

ele peek(stack s)
{
	if(isEmpty(s))
		return;
	return s->data[s->top];
}

int isPalindrome(char a[])
{
	int i=0,n;
	char b[250];
	stack t=create();
	while(a[i]!='\0')
	{
		push(t,a[i]);
		i++;
	}
	n=i;
	for(i=0;i<n;i++)
	{
		b[i]=pop(t);
	}
	b[i]='\0';
	if(strcmp(a,b)==0)
		return 1;
	else
		return 0;
}

int reverse(char *a)
{
	stack t;int i;
	t=create();
	for(i=0;i<strlen(a);i++)
	{
		push(t,a[i]);
	}
	for(i=0;i<strlen(a);i++)
	{
		a[i]=pop(t);
	}
	a[i]='\0';
	return 1;
}

int isOperator(char a)
{
	if(a=='+'||a=='-'||a=='*'||a=='/'||a=='^')
		return 1;
	return 0;
}

int precedence(char a)
{
	if(a=='^')
	{
		return 3;
	}
	else if(a=='*'||a=='/')
	{
		return 2;
	}
	else if(a=='+'||a=='-')
	{
		return 1;
	}
	else
		return 0;
}

int infixtopostfix(char infix[],char postfix[])
{
	stack t;
	t=create();
	push(t,'(');
	strcat(infix,")");
	int i=0,j=0;
	char item=infix[i];
	while(item!='\0')
	{
		if(item=='(')
			push(t,item);
		else if(isdigit(item))
		{
			postfix[j]=item;
			j++;
		}
		else if(isOperator(item)==1)
		{
			char x=pop(t);
			while(isOperator(x)==1&&precedence(x)>=precedence(item))
			{
				postfix[j]=x;
				j++;
				x=pop(t);
			}
			push(t,x);
			push(t,item);
		}
		else if(item==')')
		{
			char x=pop(t);
			while(x!='(')
			{
				postfix[j]=x;
				j++;
				x=pop(t);
			}
		}
		else
		{
			printf("INVALID FUCKA!");
			break;
		}
		i++;
		item=infix[i];
	}
	postfix[j]='\0';
	return 1;
}

int evaluatePostfix(char *a)
{
	stack t=create();
	int i;
	for(i=0;a[i]!='\0';i++)
	{
		if(isdigit(a[i]))
		{
			push(t,a[i]-'0');
		}
		else
		{
			int val1=pop(t);
			int val2=pop(t);
			switch(a[i])
			{
				case '^': push(t,pow(val2,val1));
						  break;
				case '+': push(t,val1+val2);
						  break;
				case '-': push(t,val2-val1);
						  break;
				case '*': push(t,val2*val1);
						  break;
				case '/': push(t,val2/val1);
						  break;				 
			}
		}
	}
	return pop(t);
}

int isBalanced(char *str)
{
	stack t=create();
	char x;
	int i;
	for(i=0;str[i]!='\0'; i++)
	{
		if(str[i]=='(')
			push(t,str[i]);
		if(str[i] ==')' )
		{
			if(!isEmpty(t))
			{
				x = pop(t);
				if(x != '(')
					return 0;
			}
			else
				return 0;
		}
	}
	if(!isEmpty(t))
	{
		return 0;
	}		
	return 1;
}

int main()
{
	char *b="(";
	int c=isBalanced(b);
	printf("%d",c);
	return 1;	
}
