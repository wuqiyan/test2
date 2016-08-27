/***********************************************************
*1.队列初始化时，front和rear为0；
*2.队列为空，front等于rear;
*3.队列满时，(rear + 1)%maxsize = front
*
*************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<string.h>
#include<malloc.h>
#include"queue.h"

/**************************
* create a empty stack
***************************/
void createQueue(PQUEUE Q, int maxsize)
{
	
	Q->pBase = (int *)malloc(sizeof(int)*maxsize);
	if (NULL == Q->pBase)
	{
		printf("Memory allocation failure!\n");
		exit(-1);
	} 
	Q->front = 0;
	Q->rear = 0;
	Q->maxsize = maxsize;
	
}

/************************************
*print th stack element;
*************************************/
void TraverseQueue(PQUEUE Q)
{
	int i = Q->front;
	printf("element of queue:\n");
	while (i / Q->maxsize != Q->rear)
	{
		printf("%d", Q->pBase[i]);
		i++;
	}
	printf("\n");
}

int FullQueue(PQUEUE Q)
{
	if (Q->front == (Q->rear + 1) % Q->maxsize)
		return TRUE;
	else
		return FALSE;

}

int EmptyQueue(PQUEUE Q)
{
	if (Q->front == Q->rear)
		return TRUE;
	else
		return FALSE;
}

/********************************************
* 功能：队列入队
*  1.把数据存在rear所在的位置；
*  2.rear = (rear +1)%maxsize ;
*********************************************/
int Enqueue(PQUEUE Q, int val)
{
	if (FullQueue(Q))
		return FALSE;
	else
	{
		Q->pBase[Q->rear] = val;
		Q->rear = (Q->rear + 1) % Q->maxsize;
		return TRUE;
	}
}

int DeQueue(PQUEUE Q, int *val)
{
	if (EmptyQueue(Q))
	{
		return FALSE;
	}
	else
	{
		*val = Q->pBase[Q->front];
		Q->front = (Q->front + 1) % Q->maxsize;
		return TRUE;

	}
}

int LengthQueue(PQUEUE Q)
{
	return (Q->rear - Q->front + Q->maxsize) % Q->maxsize;
}

