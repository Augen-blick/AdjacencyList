#include "AdjacencyList.h"
#include "AdjMethod.h"
using namespace std;

int main()
{
	//�ڽӾ���
	int A[MAXV][MAXV] = { {0,1,0,1,1},{1,0,1,1,0},{0,1,0,1,1},{1,1,1,0,1},{1,0,1,1,0} };

	AdjGraph* G;			//�����ڽӱ�

	//�����ڽӱ�
	CreateAdj(G, A, 5, 8);

	//����ڽӱ�
	cout << "�ڽӱ����ݣ�" << endl;
	DispAdj(G);

	//��ȱ���
	cout << "��ȱ�����" << endl;
	DFS(G, 3);
	cout << endl;

	//��ȱ���
	cout << "��ȱ�����" << endl;
	BFS(G, 3);

	//����
	DestroyAdj(G);

	return 0;
}