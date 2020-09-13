#include<stdio.h>
#include<stdlib.h>
#include<vector>
using namespace std;

void merge(vector<int> &B, vector<int> &orgId, int a, int b, int c)
{
	int i = a, j = b, k = 0;
	int* arr = (int*) malloc((c-a+1)*sizeof(int));
	int* tempIds = (int*) malloc((c-a+1)*sizeof(int));

	while(i<b && j<c)
	{
		if(B[i]<=B[j])
		{
			arr[k] = B[i];
			tempIds[k++] = orgId[i++];
		}
		else
		{
			arr[k] = B[j];
			tempIds[k++] = orgId[j++];
		}
	}
	while(i<b)
	{
		arr[k] = B[i];
		tempIds[k++] = orgId[i++];
	}
	while(j<c)
	{
		arr[k] = B[j];
		tempIds[k++] = orgId[j++];
	}
	for(i=a,j=0; i<c; i++,j++)
	{
		B[i] = arr[j];
		orgId[i] = tempIds[j];
	}
	free(arr);
	free(tempIds);


}
void mergeSort(vector<int> &B, vector<int> &orgId, int a, int b)
{
	if(b-a>1)
	{
		mergeSort(B, orgId, a, a+(b-a)/2);
		mergeSort(B, orgId, a+(b-a)/2, b);
	}
	merge(B, orgId, a, a+(b-a)/2, b);		
}

int maximumGap(vector<int> &A)
{
	int a = 0, b = 0;	//
	vector<int> ACopy(A.size());
	ACopy = A;
	vector<int> orgId(A.size());		// to store the original ID's
	for(int j = 0; j<A.size(); j++)
	{
		orgId[j] = j;
	}
	mergeSort(ACopy, orgId, 0, ACopy.size());	
	
	int maxDif = -1;
	if(A.size()>0)
	{
		int maxId = orgId.back();
		for(auto i = orgId.rbegin(); i!=orgId.rend(); i++)
		{
			if(*i>maxId)
				maxId = *i;
			if(maxId-*i>maxDif)
				maxDif = maxId-*i;
		}
	}
	return(maxDif);

}

int main()
{
	vector<int> A(5);
	A[0]=3;
	A[1]=5;
	A[2]=4;
	A[3]=2;
	A[4]=6;
	printf("%d",maximumGap(A));
	return(0);
}