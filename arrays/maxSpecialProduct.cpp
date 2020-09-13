#include<stdio.h>
#include<vector>
#include<stack>
using namespace std;


vector<int> nextGreaterRight(vector<int> &A)
{
    vector<int> B(10e5, 0);
    stack<int> s;
    int r;
    for(int i = 0; i<A.size(); i++)
    {
        while(!s.empty() && A[i]>A[s.top()])
        {
            r = s.top();
            B[r] = i;
            s.pop();
        }
        s.push(i);
    }
    return(B);
}

vector<int> nextGreaterLeft(vector<int> &A)
{
    vector<int> B(10e5, 0);
    stack<int> s;
    int r;
    for(int i = A.size()-1; i>=0; i--)
    {
        while(!s.empty() && A[i]>A[s.top()])
        {
            r = s.top();
            B[r] = i;
            s.pop();
        }
        s.push(i);
    }
    return(B);
}

int maxSpecialProduct(vector<int> &A)
{
    vector<int> rTerms = nextGreaterRight(A);
    vector<int> lTerms = nextGreaterLeft(A);
    int largest = 0;
    for(int i = 0; i<A.size(); i++)
    {
        largest = max(largest, rTerms[i]*lTerms[i]);
    }
    return((int) (largest%1000000007));
}

void printVec(vector<int> &A)
{
    for(auto i = A.begin(); i!=A.end(); i++)
        printf("%d ", *i);
    printf("\n");
}

int main()
{
    int arr[] = {5,4,3,4,5};
    vector<int> A(arr, arr+sizeof(arr)/sizeof(arr[0]));
    printVec(A);
    int largest = maxSpecialProduct(A);
    printf("%d\n", largest);
    return(0);
}