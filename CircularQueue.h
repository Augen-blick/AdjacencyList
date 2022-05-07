#pragma once
#include <iostream>
using namespace std;

const int MaxSize = 5;
typedef int ElemType;

typedef struct
{
	ElemType data[MaxSize];
	int front, rear;
} CirQueue;

void InitQueue(CirQueue*& q);						//初始化队列
void DestroyQueue(CirQueue*& q);					//销毁队列
bool QueueEmpty(CirQueue* q);						//判断队列是否为空
bool enQueue(CirQueue*& q, ElemType e);				//进队列
bool deQueue(CirQueue*& q, ElemType& e);			//出队列

void InitQueue(CirQueue*& q)						//初始化队列
{
	q = (CirQueue*)malloc(sizeof(CirQueue));
	if (q != NULL)
		q->front = q->rear = 0;
}

void DestroyQueue(CirQueue*& q)						//销毁队列
{
	free(q);
}

bool QueueEmpty(CirQueue* q)						//判断队列是否为空
{
	return(q->front == q->rear);
}

bool enQueue(CirQueue*& q, ElemType e)				//进队列
{
	if ((q->rear + 1) % MaxSize == q->front)		//队列上溢出
		return false;
	q->rear = (q->rear + 1) % MaxSize;
	q->data[q->rear] = e;
	return true;
}
bool deQueue(CirQueue*& q, ElemType& e)				//出队列
{
	if (q->front == q->rear)							//队列下溢出
		return false;
	q->front = (q->front + 1) % MaxSize;
	e = q->data[q->front];
	return true;
}