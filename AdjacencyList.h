#pragma once
#include <iostream>
#define MAXV 10
#define INF 32767
using namespace std;

typedef int InfoType;
typedef struct ANode
{
	int adjvex;					//�ñߵ��ڽӵ���
	struct ANode* nextarc;		//ָ����һ���ߵ�ָ��
	int weight;					//�ñߵ������Ϣ����Ȩֵ
}ArcNode;
typedef struct Vnode
{
	InfoType info;				//�����������Ϣ
	ArcNode* firstarc;			//ָ���һ���߽��
}VNode;							//��ӱ��ͷ�������
typedef struct
{
	VNode adjlist[MAXV];		//��ӱ��ͷ�������
	int n, e;					//ͼ�еĶ�����n�ͱ���e
}AdjGraph;						//������ͼ�ڽӱ�����

void CreateAdj(AdjGraph*& G, int A[MAXV][MAXV], int n, int e)	//����ͼ���ڽӱ�
{
	int i, j; ArcNode* p;
	G = (AdjGraph*)malloc(sizeof(AdjGraph));
	for (i = 0; i < n; i++)							//���ڽӱ�������ͷ����ָ�����ó�ֵ
		G->adjlist[i].firstarc = NULL;
	for (i = 0; i < n; i++)
		for (j = n - 1; j >= 0; j--)
		{
			if (A[i][j] != 0 && A[i][j] != INF)		//����һ����
			{
				p = (ArcNode*)malloc(sizeof(ArcNode));	//�������p
				p->adjvex = j;							//����ڽӵ�
				p->weight = A[i][j];					//���Ȩֵ
				p->nextarc = G->adjlist[i].firstarc;	//ͷ�巨����p
				G->adjlist[i].firstarc = p;
			}
		}
	G->n = n, G->e = e;
}

void DispAdj(AdjGraph* G)					//����ڽӱ�G
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
		cout << "��" << endl;
	}
}

void DestroyAdj(AdjGraph*& G)				//�����ڽӱ�
{
	int i; ArcNode* pre, * p;
	for (i = 0; i < G->n; i++)				//ɨ�����еĵ�����
	{
		pre = G->adjlist[i].firstarc;		//pָ���i���������ͷ���
		if (pre != NULL)
		{
			p = pre->nextarc;
			while (p!=NULL)					//�ͷŵ�i������������б߽��
			{
				free(pre);
				pre = p;
				p = p->nextarc;
			}
			free(pre);
		}
	}
	free(G);								//�ͷ�ͷ�������
}