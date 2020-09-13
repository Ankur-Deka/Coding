#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

// Definition for an interval.
struct Interval
{
 int start;
 int end;
 Interval() : start(0), end(0) {}
 Interval(int s, int e) : start(s), end(e) {}
};

bool comp(Interval a, Interval b)
{
	return(a.start<b.start);
}

// void merging(vector<Interval> &A, int a, int b, int c)
// {
// 	vector<Interval> tempIntv(c-a+1);
// 	int i = a, j = b, k = 0;
// 	while(i!=b && j!=c)
// 	{
// 		if(A[i].start<=A[j].start)
// 			tempIntv[k++] = A[i++];
// 		else
// 			tempIntv[k++] = A[j++];
// 	}
// 	while(i!=b)
// 		tempIntv[k++] = A[i++];
// 	while(j!=c)
// 		tempIntv[k++] = A[j++];
// 	for(i = a, k = 0; i<c; i++, k++)
// 		A[i] = tempIntv[k];
// }

// void mergeSort(vector<Interval> &A, int a, int b)
// {
// 	if(b-a>1)
// 	{
// 		mergeSort(A, a, a+(b-a)/2);
// 		mergeSort(A, a+(b-a)/2, b);
// 	}
// 	merging(A, a, a+(b-a)/2, b);
// }
 
vector<Interval> merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	
	// If length <2 then nothing to do
	if(A.size()<2)
		return(A);

	sort(A.begin(), A.end(), comp);

	vector<Interval> B;
	auto a = A.begin(), b = A.begin()+1;

	while(b!=A.end())
	{
		// overlap exists
		if((*a).end>=(*b).start)
		{
			(*a).end = max((*a).end, (*b).end);
			b++;	
		}
		// overlap doesn't exist
		else
		{
			B.push_back(*a);
			a = b;
			b++;
		}

	}
	B.push_back(*a);
	return(B);
}


void printVec(vector<Interval> &vecIntv)
{
	for(auto i = vecIntv.begin(); i!=vecIntv.end(); i++)
	{
		printf("%d, %d\n", (*i).start, (*i).end);
	}
}
int main()
{
	vector<Interval> vecIntv(6);
	vecIntv[0].start = 4;
	vecIntv[0].end = 10;
	vecIntv[1].start = 2;
	vecIntv[1].end = 9;
	vecIntv[2].start = 3;
	vecIntv[2].end = 8;
	vecIntv[3].start = 4;
	vecIntv[3].end = 7;
	vecIntv[4].start = 1;
	vecIntv[4].end = 2;
	vecIntv[5].start = 6;
	vecIntv[5].end = 6;

// [ (1, 10), (2, 9), (3, 8), (4, 7), (5, 6), (6, 6) ]
	// [ (4, 100), (48, 94), (16, 21), (58, 71), (36, 53), (49, 68), (18, 42), (37, 90), (68, 75), (6, 57), (25, 78), (58, 79), (18, 29), (69, 94), (5, 31), (10, 87), (21, 35), (1, 32), (7, 24), (17, 85), (30, 95), (5, 63), (1, 17), (67, 100), (53, 55), (30, 63), (7, 76), (33, 51), (62, 68), (78, 83), (12, 24), (31, 73), (64, 74), (33, 40), (51, 63), (17, 31), (14, 29), (9, 15), (39, 70), (13, 67), (27, 100), (10, 71), (18, 47), (48, 79), (70, 73), (44, 59), (68, 78), (24, 67), (32, 70), (29, 94), (45, 90), (10, 76), (12, 28), (31, 78), (9, 44), (29, 83), (21, 35), (46, 93), (66, 83), (21, 72), (29, 37), (6, 11), (56, 87), (10, 26), (11, 12), (15, 88), (3, 13), (56, 70), (40, 73), (25, 62), (63, 73), (47, 74), (8, 36) ]
	printf("Before Merging:\n");
	printVec(vecIntv);
	vector<Interval> newVecIntv = merge(vecIntv);
	printf("After Merging:\n");
	printVec(newVecIntv);



}