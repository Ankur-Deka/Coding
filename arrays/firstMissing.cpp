#include<stdio.h>
#include<vector>
using namespace std;
void printVec(vector<int> &A)
{
	for(auto i = A.begin(); i!=A.end(); i++)
		printf("%d ", *i);
	printf("\n");
}

int firstMissingPositive(vector<int> &A)
{
	int val, temp;
	for(int i = 0; i<A.size(); i++)
	{
		// printf("i = %d\n", i);
		val = A[i];
		while(val>=1 && val<=A.size() && val!=A[val-1])
		{
			// printf("In while i = %d, val = %d\n", i,  val);
			temp = A[val-1];
			A[val-1] = val;
			val = temp;
		}
	}
	val = A.size()+1;
	for(int i = 0; i<A.size(); i++)
	{
		if(A[i]!=i+1)
		{
			val = i+1;
			break;
		}
	}
	return(val);
}

int main()
{
	vector<int> A{-8, -7, -6};
	printVec(A);
	printf("First missing positive int %d\n", firstMissingPositive(A));
	printVec(A);
	return(0);
}


