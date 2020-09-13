#include<stdio.h>
#include<vector>
using namespace std;

void print1DVec(vector<int> &A)
{
	for(int i = 0; i<A.size(); i++)
		printf("%d ", A[i]);
	printf("\n");
}

void print2DVec(vector<vector<int>> &A)
{
	for(int i = 0; i<A.size(); i++)
		print1DVec(A[i]);
}

void setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details


	/*	Strategy 1:
		traverse through the array - O(M*N):
			store a list of rows - will automatically be sorted, therefore trivial to not repeat terms O(1)
			store a list of columns - might have to shift terms, O(N). If I use a heap, then O(log(N))
		then traverse again to set the values - O(M*N)


		net worst case time complexity O(M*N*log(N))
		worst case space complexity O(M+N)

		Strategy 2:
		Traverse through the array twice:
	   		rowwise and store the list of rows
	   		columnwise and store the list of columns
	   	time complexity O(M*N)
	   	space complexity O(M+N)

		I don't think we can get better than this
	*/

	vector<int> rows;
	vector<int> columns;

	// Rowise traversal
	for(int i = 0; i<A.size(); i++)
	{
		for(int j = 0; j<A[i].size(); j++)
		{
			if(A[i][j] == 0)
			{
				rows.push_back(i);
				break;
			}
		}
	}

	// Columnwise traversal
	for(int j = 0; j<A[0].size(); j++)
	{
		for(int i = 0; i<A.size(); i++)
		{
			if(A[i][j] == 0)
			{
				columns.push_back(j);
				break;
			}
		}
	}

	for(auto i = rows.begin(); i!=rows.end(); i++)
	{
		for(auto j = A[*i].begin(); j!=A[*i].end(); j++)
		{
			*j = 0; 
		}
	}
	for(auto j = columns.begin(); j!=columns.end(); j++)
	{
		for(int i = 0; i<A.size(); i++)
		{
			A[i][*j] = 0;
		}
	}

}



int main(int argc, char const *argv[])
{
	vector<vector<int>> A{{1, 0, 1}, {1, 1, 1}, {1, 1, 1}};
	print2DVec(A);
	setZeroes(A);
	print2DVec(A);
	//
	return 0;
}