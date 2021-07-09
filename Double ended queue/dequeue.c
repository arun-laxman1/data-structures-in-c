#include<stdio.h>
#include<stdlib.h>
#define maxi 20
typedef char type;

typedef struct
{
    type *data;
    int front;
    int rear;
}dequeue;

dequeue* create()
{
    dequeue *q = (dequeue*)malloc(sizeof(dequeue));
    q->data=(type*)malloc(sizeof(type)*maxi);
    q->front = -1;
    q->rear = -1;
    return q;
}
int enqueue_rear(dequeue *q, type x)
{
    if(q->rear == -1)
    {
        (q->front)++;
        (q->rear)++;
        q->data[q->rear] = x;
    }
    else
    {
        q->rear = (q->rear+1)%maxi;
        q->data[q->rear] = x;
    }
    return 0;
}
int enqueue_front(dequeue *q, type x)
{
    if(q->rear == -1)
    {
        (q->front)++;
        (q->rear)++;
        q->data[q->front] = x;
    }
    else
    {
        q->front = (q->front-1 + maxi)%maxi;
        q->data[q->front] = x;
    }
    return 0;
}
type dequeue_front(dequeue * q)
{
    type x = q->data[q->front];
    if(q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front = (q->front+1)%maxi;
    }
    return x;
}
type dequeue_rear(dequeue * q)
{
    type x = q->data[q->rear];
    if(q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->rear = (q->rear-1 + maxi)%maxi;
    }
    return x;
}
int print(dequeue *q)
{
	if(q->rear == -1)
	{
		printf("\nQueue is empty!!");
		return;
	}

	int i;
	i=q->front;

	while(i!=q->rear)
	{
		printf("%c\t",q->data[i]);
		i=(i+1)%maxi;
	}

	printf("%c\t",q->data[q->rear]);
	return 0;
}
int palindrome(dequeue * q, char*str)
{
    int n = strlen(str);
    n = n/2;
    while(n)
    {
        if(dequeue_front(q) != dequeue_rear(q))
        {
            return 0;
        }
        n--;
    }
    return 1;
}
int main()
{
    dequeue * temp = create();
    char * str = "dad";
    int i = 0;
    while(str[i] != '\0')
    {
        enqueue_front(temp, str[i]);
        i++;
    }
    if(palindrome(temp,str))
    {
        printf("PALINDROME");
    }
    else
    {
        printf("NOT A PALINDROME");
    }
    return 0;
}
