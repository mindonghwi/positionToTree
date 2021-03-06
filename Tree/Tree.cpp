// Tree.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include<queue>
#include <vector>
//좌표가 주어질거다 이것으로 트로를 만들어라

int arData[1000000]{};

void FindLeftNodes(std::vector<int> vecNodes, std::vector<std::vector<int>> vecNodePosList,int nIndex);
void FindRightNodes(std::vector<int> vecNodes, std::vector<std::vector<int>> vecNodePosList, int nIndex);
int main()
{
	std::queue<int> queData;
	std::vector<std::vector<int>> vecNodePosList;
	std::vector<int> vecPos;
	std::vector<int> vecLeft;
	std::vector<int> vecRight;
	int nNodeCount(0);
	int nTmpX(0);
	int nTmpY(0);
	scanf_s("%d", &nNodeCount);

	while (nNodeCount--)
	{
		scanf_s("%d %d", &nTmpX,&nTmpY);
		vecPos.push_back(nTmpX);
		vecPos.push_back(nTmpY);
		vecNodePosList.push_back(vecPos);
		vecPos.clear();
	}
	//루트노드 찾기
	int nMaxIndex(0);
	for (int i = 1; i < (int)vecNodePosList.size(); i++)
	{
		if (vecNodePosList[nMaxIndex][1] < vecNodePosList[i][1])
		{
			nMaxIndex = i;
		}
	}

	arData[1] = nMaxIndex;

	//post식으로 왼쪽찾기 왼쪽 구하고 오른쪽 나누고  그중 잴 큰거 
	for (int i = 0; i < (int)vecNodePosList.size(); i++)
	{
		if (vecNodePosList[nMaxIndex][0] < vecNodePosList[i][0])
		{
			vecRight.push_back(i);
		}
		else if (vecNodePosList[nMaxIndex][0] > vecNodePosList[i][0])
		{
			vecLeft.push_back(i);
		}
	}

	FindLeftNodes(vecLeft,vecNodePosList,2);
	FindRightNodes(vecRight, vecNodePosList,3);

	printf("%d %d\n", 1, arData[1]);
	for (int i = 2; i <1000; i++)
	{
		if (arData[i] != 0)
		{
			printf("%d %d\n", i, arData[i]);
		}
	}

    return 0;
}

void FindLeftNodes(std::vector<int> vecNodes, std::vector<std::vector<int>> vecNodePosList, int nIndex)
{
	if (vecNodes.empty())
	{
		return;
	}

	std::vector<int> vecLeft;
	std::vector<int> vecRight;

	int nMaxIndex(0);
	for (int i = 1; i < (int)vecNodes.size(); i++)
	{
		if (vecNodePosList[vecNodes[nMaxIndex]][1] < vecNodePosList[vecNodes[i]][1])
		{
			nMaxIndex = i;
		}
	}
	arData[nIndex] = vecNodes[nMaxIndex];

	//post식으로 왼쪽찾기 왼쪽 구하고 오른쪽 나누고  그중 잴 큰거 
	for (int i = 0; i < (int)vecNodes.size(); i++)
	{
		if (vecNodePosList[vecNodes[nMaxIndex]][0] < vecNodePosList[vecNodes[i]][0])
		{
			vecRight.push_back(vecNodes[i]);
		}
		else if (vecNodePosList[vecNodes[nMaxIndex]][0] > vecNodePosList[vecNodes[i]][0])
		{
			vecLeft.push_back(vecNodes[i]);
		}
	}
	FindLeftNodes(vecLeft, vecNodePosList,2*nIndex);
	FindRightNodes(vecRight, vecNodePosList, 2 * nIndex+1);
}

void FindRightNodes(std::vector<int> vecNodes, std::vector<std::vector<int>> vecNodePosList, int nIndex)
{
	if (vecNodes.empty())
	{
		return;
	}

	std::vector<int> vecLeft;
	std::vector<int> vecRight;

	int nMaxIndex(0);
	for (int i = 1; i < (int)vecNodes.size(); i++)
	{
		if (vecNodePosList[vecNodes[nMaxIndex]][1] < vecNodePosList[vecNodes[i]][1])
		{
			nMaxIndex = i;
		}
	}
	arData[nIndex] = vecNodes[nMaxIndex];

	//post식으로 왼쪽찾기 왼쪽 구하고 오른쪽 나누고  그중 잴 큰거 
	for (int i = 0; i < (int)vecNodes.size(); i++)
	{
		if (vecNodePosList[vecNodes[nMaxIndex]][0] < vecNodePosList[vecNodes[i]][0])
		{
			vecRight.push_back(vecNodes[i]);
		}
		else if (vecNodePosList[vecNodes[nMaxIndex]][0] > vecNodePosList[vecNodes[i]][0])
		{
			vecLeft.push_back(vecNodes[i]);
		}
	}
	FindLeftNodes(vecLeft, vecNodePosList, 2 * nIndex);
	FindRightNodes(vecRight, vecNodePosList, 2 * nIndex + 1);
}