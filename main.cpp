#include "AdjacencyList.h"
#include "AdjMethod.h"
using namespace std;

int main()
{
	//邻接矩阵
	int A[MAXV][MAXV] = { {0,1,0,1,1},{1,0,1,1,0},{0,1,0,1,1},{1,1,1,0,1},{1,0,1,1,0} };

	AdjGraph* G;			//定义邻接表

	//创建邻接表
	CreateAdj(G, A, 5, 8);

	//输出邻接表
	cout << "邻接表内容：" << endl;
	DispAdj(G);

	//深度遍历
	cout << "深度遍历：" << endl;
	DFS(G, 3);
	cout << endl;

	//广度遍历
	cout << "广度遍历：" << endl;
	BFS(G, 3);

	//销毁
	DestroyAdj(G);

	return 0;
}