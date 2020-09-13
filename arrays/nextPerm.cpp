#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

void nextPermutation(vector<int>& nums)
{
	int i = 0;
	for(i = nums.size()-1; i>0; i--)
	{
		if(nums[i]>nums[i-1])
			break;
	}
	// if next permute not possible
	if(i==0)
		sort(nums.begin(), nums.end());
	
	else
	{	
		i -= 1;
		int k = nums.size()-1;
		for(int j = i+1; j<nums.size(); j++)
		{
			if(nums[j]<nums[i])
			{
				k = j-1;
				break;
			}
		}
		// printf("i %d k %d \n", i, k);
		swap(nums[i], nums[k]);
		sort(nums.begin()+i+1, nums.end());
	}

}

void printArr(vector<int> v)
{
	for(auto i = v.begin(); i<v.end();i++)
		printf("%d ", *i);
}
int main()
{
	vector<int> v = {2,3};
	printArr(v);
	nextPermutation(v);
	printArr(v);
	return 0;
}