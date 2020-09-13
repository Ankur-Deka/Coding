#include<stdio.h>
#include<vector>
using namespace std;

int main(int argc, char const *argv[])
{
	// vector<int> v{1,2,3};
	// for(auto i = v.begin();i!=v.end(); i++)
	// 	printf("%d ", *i);
	vector<vector<int>> v2{{1,2,3}, {4,5,6}, {7,8,9}};
	for(auto i = v2.begin(); i!=v2.end(); i++)
	{
		for(auto j = (*i).begin(); j!=(*i).end(); j++)
		{
			printf("%d ", *j);
		}
		printf("\n");
	}

	v2[0].push_back(0);
	for(int i = 0; i<v2.size(); i++)
	{
		for(int j = 0; j<v2[i].size(); j++)
		{
			printf("%d ", v2[i][j]);
		}
		printf("\n");
	}
	return 0;
}