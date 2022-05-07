#pragma once
#include <iostream>
#define MAXV 10
#define INF 32767
using namespace std;

typedef int InfoType;
typedef struct ANode
{
	int adjvex;					//该边的邻接点编号
	struct ANode* nextarc;		//指向下一条边的指针
	int weight;					//该边的相关信息，如权值
}ArcNode;
typedef struct Vnode
{
	InfoType info;				//顶点的其他信息
	ArcNode* firstarc;			//指向第一个边结点
}VNode;							//领接表的头结点类型
typedef struct
{
	VNode adjlist[MAXV];		//领接表的头结点数组
	int n, e;					//图中的顶点数n和边数e
}AdjGraph;						//完整的图邻接表类型

void CreateAdj(AdjGraph*& G, int A[MAXV][MAXV], int n, int e)	//创建图的邻接表
{
	int i, j; ArcNode* p;
	G = (AdjGraph*)malloc(sizeof(AdjGraph));
	for (i = 0; i < n; i++)							//给邻接表中所有头结点的指针域置初值
		G->adjlist[i].firstarc = NULL;
	for (i = 0; i < n; i++)
		for (j = n - 1; j >= 0; j--)
		{
			if (A[i][j] != 0 && A[i][j] != INF)		//存在一条边
			{
				p = (ArcNode*)malloc(sizeof(ArcNode));	//创建结点p
				p->adjvex = j;							//存放邻接点
				p->weight = A[i][j];					//存放权值
				p->nextarc = G->adjlist[i].firstarc;	//头插法插入p
				G->adjlist[i].firstarc = p;
			}
		}
	G->n = n, G->e = e;
}

void DispAdj(AdjGraph* G)					//输出邻接表G
{
	int i; ArcNode* p;
	for (i = 0; i < G->n; i++)
	{
		p = G->adjlist[i].firstarc;
		cout << i << ": ";
		while (p!=NULL)
		{
			cout << p->adjvex << "[" << p->weight << "]->";
			p = p->nextarc;
		}
		cout << "∧" << endl;
	}
}

void DestroyAdj(AdjGraph*& G)				//销毁邻接表
{
	int i; ArcNode* pre, * p;
	for (i = 0; i < G->n; i++)				//扫描所有的单链表
	{
		pre = G->adjlist[i].firstarc;		//p指向第i个单链表的头结点
		if (pre != NULL)
		{
			p = pre->nextarc;
			while (p!=NULL)					//释放第i个单链表的所有边结点
			{
				free(pre);
				pre = p;
				p = p->nextarc;
			}
			free(pre);
		}
	}
	free(G);								//释放头结点数组
}