// Problem: Little Bishops UVA 861
// Author: Diaa Abdallah

#include <iostream>
#include <math.h>
#include <cstdlib>
using namespace std;
int board_size;
int board_sizeSqrt;

bool isInDiagonal(int a,int b,int n)
{
	int aRow=a/n;
	int aColumn=a%n;
	int bRow=b/n;
	int bColumn=b%n;
	if(a==b)
		return true;
	if( abs(aRow-bRow)==abs(aColumn-bColumn))
		return true;
	return false;
}
int constructCandidates(int solution_position,int* partial_solution,int bishops,int* candidates)
{
	//return array of possible positions and its size
	int solutionsCount=0;
	int candPos=0;
	int start=0;
	if(solution_position)
		start=partial_solution[solution_position-1];
	for(int i=start;i<board_size;i++)//check possible elements after current
	{
		bool solutionFound=true;
		for(int j=0;j<solution_position;j++)//Check previous entries 
		{
			if(isInDiagonal(partial_solution[j],i,board_sizeSqrt))
			{
				solutionFound=false;
				break;
			}
		}
		if(solutionFound)
		{
			solutionsCount++;
			candidates[candPos]=i;
			candPos++;
		}	
	}
	return solutionsCount;
}
long count=0;
void backtrack(int solution_position, int* partial_solution,int bishops)
{
	if(solution_position==bishops)
	{
		::count++;
		return;
	}
	int* candidates=new int[board_size];
	int candidateNum=constructCandidates(solution_position,partial_solution,bishops,candidates);//O(n^2)
	for(int i=0;i<candidateNum;i++)
	{
		partial_solution[solution_position]=candidates[i];
		backtrack(solution_position+1,partial_solution,bishops);
	}
	delete[] candidates;
}
void solutions(int n,int bishops)
{
	if(n*n==bishops)
		return;
	int* partial_solution=new int[bishops];
	::board_size=n*n;
	backtrack(0,partial_solution,bishops);
	delete[] partial_solution;
}
int main()
{
	int board_size, bishops;

	while(cin>>board_size>>bishops)
	{
		if(board_size==0&&bishops==0)
			return 0;
		::count=0;
		board_sizeSqrt=board_size;
		solutions(board_size,bishops);
		cout<<::count<<endl;
	}

	return 0;
}
