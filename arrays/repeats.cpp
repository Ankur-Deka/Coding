#include<iostream>
#include<vector>

using namespace std;
int abs(int a)
{
	return(a>=0?a:-a);
}

int main()
{	
	int arr[] = {2,4,3,2,4,3}, n = 6, id, val;
	vector<int> repeats;

	for(int i = 0; i<n; i++)
	{
		id = abs(arr[i]);
		val = arr[id-1];

		if(val<0)
			repeats.push_back(-val);	// value was already seen
		else
			arr[id-1] = -val;			// indicate that we've seen the value
	}
	for(auto i = repeats.begin(); i!=repeats.end(); i++)
		printf("%d ", *i);
	printf("\n");
	return(0);
}