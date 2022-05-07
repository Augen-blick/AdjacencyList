#pragma once
#include "AdjacencyList.h"
#include "CircularQueue.h"
#define MAX 10

int visited[MAX] = { 0 };			//ȫ������

void DFS(AdjGraph* G, int v)			//������ȱ����㷨
{
	ArcNode* p;
	visited[v] = 1;					//���ѷ��ʱ��
	cout << v << " ";						//��������ʶ���ı��
	p = G->adjlist[v].firstarc;		//pָ�򶥵�v�ĵ�һ���ڽӵ�
	while (p!=NULL)
	{
		if (visited[p->adjvex] == 0)	//��p->adjvex����δ�����ʣ��ݹ������
			DFS(G, p->adjvex);
		p = p->nextarc;				//pָ�򶥵�v����һ���ڽӵ�
	}
}

void BFS(AdjGraph* G, int v)				//������ȱ����㷨
{
	int w, i; ArcNode* p;
	CirQueue* qu;					//���廷�ζ���ָ��
	InitQueue(qu);					//��ʼ������
	int visited[MAXV];				//���嶥����ʱ������
	for (i = 0; i < G->n; i++)
		visited[i] = 0;				//���ʱ�������ʼ��
	cout << v << " ";						//��������ʶ���ı��
	visited[v] = 1;					//���ѷ��ʱ��
	enQueue(qu, v);
	while (!QueueEmpty(qu))			//�Ӳ���ѭ��
	{
		deQueue(qu, w);				//����һ������w
		p = G->adjlist[w].firstarc;	//ָ��w�ĵ�һ���ڽӵ�
		while (p != NULL)			//����w�������ڽӵ�
		{
			if (visited[p->adjvex] == 0)	//����ǰ�ڽӵ�δ������
			{
				cout << p->adjvex << " ";	//���ʸ��ڽӵ�
				visited[p->adjvex] = 1;		//���ѷ��ʱ��
				enQueue(qu, p->adjvex);		//�ö������
			}
			p = p->nextarc;					//����һ���ڽӵ�
		}
	}
	cout << endl;
}

bool Connect(AdjGraph* G)				//�ж�����ͼG�Ƿ���ͨ
{
	int i;
	bool flag = true;
	for (i = 0; i < G->n; i++)			//�ó�ֵ
		visited[i] = 0;
	DFS(G, 0);
	for(i = 0;i<G->n;i++)
		if (visited[i] == 0)			//����ж���δ�����ʣ�����ͨ
		{
			flag = false;
			break;
		}
	return flag;
}