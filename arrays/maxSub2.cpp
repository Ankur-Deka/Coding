#include<iostream>
#include<vector>

std::vector<int> maxSub(std::vector<int> a)
{
	int sumSoFar = a[0], maxSumSoFar = a[0], start = 0, end = 0;
	std::vector<int> v = {a[0], start, end};
	for(end = 1; end<a.size(); end++)
	{
		if(sumSoFar < 0)
		{
			sumSoFar = a[end];
			start = end;
		}
		else
			sumSoFar += a[end];
		if(maxSumSoFar < sumSoFar)
		{
			maxSumSoFar = sumSoFar;
			v[0] = maxSumSoFar;
			v[1] = start;
			v[2] = end;
		}
	}
	return(v);
}	

int main()
{
	std::vector<int> a = {1,-2,2,3,-2,-4};

	printf("The array is [");
	for(auto i = a.begin(); i<a.end(); i++)
		printf("%d ", *i);
	printf("]\n");

	std::vector<int> v = maxSub(a);

	int maxSum = v[0], start = v[1], end = v[2];
	
	printf("Subarray with max sum = [");
	for(int i = start; i<=end; i++)
		printf("%d ", a[i]);
	printf("]\n");
	printf("Max sum of contiguous subarray = %d\n", v[0]);

	return(0);	
}