#pragma once
#include "AdjacencyList.h"
#include "CircularQueue.h"
#define MAX 10

int visited[MAX] = { 0 };			//全局数组

void DFS(AdjGraph* G, int v)			//深度优先遍历算法
{
	ArcNode* p;
	visited[v] = 1;					//置已访问标记
	cout << v << " ";						//输出被访问顶点的编号
	p = G->adjlist[v].firstarc;		//p指向顶点v的第一个邻接点
	while (p!=NULL)
	{
		if (visited[p->adjvex] == 0)	//若p->adjvex顶点未被访问，递归访问它
			DFS(G, p->adjvex);
		p = p->nextarc;				//p指向顶点v的下一个邻接点
	}
}

void BFS(AdjGraph* G, int v)				//广度优先遍历算法
{
	int w, i; ArcNode* p;
	CirQueue* qu;					//定义环形队列指针
	InitQueue(qu);					//初始化队列
	int visited[MAXV];				//定义顶点访问标记数组
	for (i = 0; i < G->n; i++)
		visited[i] = 0;				//访问标记数组初始化
	cout << v << " ";						//输出被访问顶点的编号
	visited[v] = 1;					//置已访问标记
	enQueue(qu, v);
	while (!QueueEmpty(qu))			//队不空循环
	{
		deQueue(qu, w);				//出队一个顶点w
		p = G->adjlist[w].firstarc;	//指向w的第一个邻接点
		while (p != NULL)			//查找w的所有邻接点
		{
			if (visited[p->adjvex] == 0)	//若当前邻接点未被访问
			{
				cout << p->adjvex << " ";	//访问该邻接点
				visited[p->adjvex] = 1;		//置已访问标记
				enQueue(qu, p->adjvex);		//该顶点进队
			}
			p = p->nextarc;					//找下一个邻接点
		}
	}
	cout << endl;
}

bool Connect(AdjGraph* G)				//判断无向图G是否连通
{
	int i;
	bool flag = true;
	for (i = 0; i < G->n; i++)			//置初值
		visited[i] = 0;
	DFS(G, 0);
	for(i = 0;i<G->n;i++)
		if (visited[i] == 0)			//如果有顶点未被访问，则不连通
		{
			flag = false;
			break;
		}
	return flag;
}