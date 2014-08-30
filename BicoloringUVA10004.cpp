//Problem:Bicoloring UVA 10004
//Author: Diaa
#include<iostream>
#include<vector>
#include<list>
#include <queue>
#include<cstring>
using namespace std;
class graph{
public:
	vector<list<int> > adjacencyList;
	int nodes;
	graph(int nodes)
	{
		this->nodes=nodes;
		for(int i=0;i<nodes;i++)
			adjacencyList.push_back(list<int>());
	}
	void insertEdge(int a,int b)
	{
		adjacencyList[a].push_back(b);
		adjacencyList[b].push_back(a);
	}
};
bool bicolor(graph g)
{
	std::queue<int> q;
	q.push(0);
	int* color=new int[g.nodes];
	memset(color,0,g.nodes*sizeof(int));
	color[0]=1;
	while(!q.empty())
	{
		int currentNode=q.front();
		q.pop();
		for(list<int>::iterator it=g.adjacencyList[currentNode].begin();it!=g.adjacencyList[currentNode].end();it++)
		{
			int neighborNode=*it;
			if(color[neighborNode]==color[currentNode])//incorrectColor
				return false;
			else if(color[neighborNode]==0)//unexplored
			{
				q.push(neighborNode);
				color[neighborNode]=color[currentNode]==1?2:1;
			}
		}
	}
	return true;
}
int main()
{
	int n=-1;
	while(n!=0)
	{
		cin>>n;
		if(n!=0)
		{
			int edges,a,b;
			cin>>edges;
			graph g(n);
			for(int i=0;i<edges;i++)
			{
				cin>>a>>b;
				g.insertEdge(a,b);
			}
			if(bicolor(g))
				cout<<"BICOLORABLE."<<endl;
			else
				cout<<"NOT BICOLORABLE."<<endl;
		}
	}
	return 0;
}