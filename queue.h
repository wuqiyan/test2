#ifndef _QUEUE_H
#define _QUEUE_H
#include<stdlib.h>
#include<stdio.h>
typedef struct queue
{
	int *pBase;
	int front;
	int rea;r
	int maxsize;

}QUEUE,*PQUEUE;

void CreateQueue(PQUEUE Q,int maxsize);
void TranverseQueue(PQUEUE Q);
int FullQueue(PQUEUE Q);
int EmptyQueue(PQUEUE Q);
int EnQueue(PQUEUE Q, int val);
int DeQueue(PQUEUE Q, int *val);
int LengthQueue(PQUEUE Q);

#endif // !_QUEUE_H
