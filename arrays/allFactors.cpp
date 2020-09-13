#include<stdio.h>
#include<vector>
#include<math.h>
using namespace std;

void printVec(vector<int> &A)
{
	for(auto i = A.begin(); i!=A.end(); i++)
		printf("%d ", *i);
	printf("\n");
}

vector<int> allFactors(int A)
{
	vector<int> vec;
	for(int i = 1; i<sqrt(A); i++)
	{
		if(A%i==0)
			vec.push_back(i);
	}
	for(int i = sqrt(A); i>0; i--)
	{
		if(A%i==0)
			vec.push_back(A/i);
	}
	return(vec);
}


int main()
{
	vector<int> values = allFactors(25);
	printVec(values);
	return(0);
}