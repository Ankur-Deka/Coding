#include<bits/stdc++.h>
using namespace std;
template<typename T>
void printVec(vector<T>& vec)
{
    for(auto v: vec)
        cout<<v<<' ';
    cout<<'\n';
}

template<typename T>
void print2dVec(vector<vector<T>>& vec)
{
    for(vector<T> v: vec)
        printVec(v);
    cout<<'\n';
}

// input must be non-empty square
void rotate(vector<vector<int>>& matrix)
	{
		int s = matrix.size(), tmp;
 		for(int i = 0; i<s/2; i++)
 		{
	    	for(int j = 0; j<s-1-2*i; j++)
	    	{
	    		cout<<i<<' '<<j<<'\n';
	    		tmp = matrix[i][i+j];
	    		matrix[i][i+j] = matrix[s-1-i-j][i];
	    		matrix[s-1-i-j][i] = matrix[s-1-i][s-1-i-j];
	    		matrix[s-1-i][s-1-i-j] = matrix[i+j][s-1-i];
	    		matrix[i+j][s-1-i] = tmp;
	    	}
    	}    
    }

int main()
{
	vector<vector<int>> image{vector<int> {1,2,3,4}, vector<int> {5,6,7,8}, vector<int> {9,10,11,12}, vector<int> {13, 14, 15, 16}};
	print2dVec(image);
	rotate(image);
	print2dVec(image);

	return 0;
}