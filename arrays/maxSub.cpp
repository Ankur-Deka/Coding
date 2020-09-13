// Sample code to try finding sum of contiguous subarray using cpp vectors 

#include<stdio.h>
#include<vector>
using namespace std;

int maxSub(vector<int> *a)
{
	int maxEndingHere = (*a).at(0), maxTillHere = (*a).at(0);
	for(int i = 1; i<(*a).size(); i++)
	{
		if(maxEndingHere>0)
			maxEndingHere+=(*a).at(i);
		else
			maxEndingHere = (*a).at(i);
		if(maxTillHere<maxEndingHere)
			maxTillHere = maxEndingHere;
	}
	return(maxTillHere);
}

int main()
{
	vector<int> a(5);
	a[0] = -1;
	a[1] = 0;
	a[2] = 1;
	a[3] = -5;
	a[4] = 8;
	int maxSum = maxSub(&a);
	printf("Max sum of contiguous subarray is %d\n", maxSum);
	return 0;
}