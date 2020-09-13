#include<stdio.h>
#include<stdlib.h>

// correct but inefficient O(n^2) code
int maxSubArray(const int* A, int n1) {
    int* sum = (int*) malloc(n1*sizeof(int));
    int* maxSum = (int*) malloc(n1*sizeof(int));
    int tempSum, max, i, j;
    
    // create CDF
    sum[0] = A[0]; max = A[0];
    for(i = 1; i < n1; i++)
        sum[i] = sum[i-1] + A[i];
    
    //compute max sum for each start ID
    for(i = 0; i < n1; i++)
    {
        maxSum[i] = A[i];
        if(maxSum[i]>max)
            max = maxSum[i];
        for(j = i+1; j< n1; j++)
        {
            if(i == 0)
                tempSum = sum[j];
            else
                tempSum = sum[j] - sum[i-1];
            if(tempSum>maxSum[i])
            {

                maxSum[j] = tempSum;
                if(maxSum[j]>max)
                    max = maxSum[j]; 
            }
        }
    }
    
    return(max);
        
}


// following function supports only if array has atleast one non-negative number
// O(n) code
int maxSubArray2(const int* A, int n1)
{
    int maxSoFar = 0, maxEndingHere = 0;

    //one pass through the array
    for(int i = 0; i < n1; i++)
    {
        maxEndingHere = maxEndingHere + A[i];
        if(maxEndingHere < 0)
            maxEndingHere = 0;
        else if(maxEndingHere > maxSoFar)
            maxSoFar = maxEndingHere;
    }
    return(maxSoFar);
}

int max(int a, int b)
{
    if(a>=b)
        return a;
    else
        return b;
}

// following is both completely correct and efficient, O(n)
int maxSubArray3(const int* A, int n1)
{
    int maxSoFar = A[0], maxEndingHere = A[0], i;
    for(i = 1; i < n1; i++)
    {
        maxEndingHere = max(maxEndingHere+A[i], A[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    return(maxSoFar);
}

int main()
{
    int A[] = {-76, -30};
    int max = maxSubArray3(A, 2);
    printf("%d\n", max);
    return 0;
}



Wrong Answer. Your program's output doesn't match the expected output. You can try testing your code with custom input and try putting debug statements in your code.

Your submission failed for the following input:
A : "01010110"
Your function returned the following :
1 8 
The expected returned value :
1 1 


A : "0111000100010"
Your function returned the following :
1 11 
The expected returned value :
5 11 




Wrong Answer. Your program's output doesn't match the expected output. You can try testing your code with custom input and try putting debug statements in your code.

Your submission failed for the following input:
A : "1101010001"
Your function returned the following :
7 9 
The expected returned value :
3 9


Wrong Answer. Your program's output doesn't match the expected output. You can try testing your code with custom input and try putting debug statements in your code.
    
Your submission failed for the following input:
A : [ 0, 0, -1, 0 ]
Your function returned the following :
0 -1 0 
The expected returned value :
0 0 

Wrong Answer. Your program's output doesn't match the expected output. You can try testing your code with custom input and try putting debug statements in your code.

Your submission failed for the following input:
A : [ 1967513926, 1540383426, -1303455736, -521595368 ]
Your function returned the following :
1967513926 
The expected returned value :
1967513926 1540383426 



Wrong Answer. Your program's output doesn't match the expected output. You can try testing your code with custom input and try putting debug statements in your code.

Your submission failed for the following input:
A : [ 1159126505, -1632621729, 1433925857, 84353895, 2001100545, 1548233367, -1585990364 ]
Your function returned the following :
1433925857 84353895 2001100545 
The expected returned value :
1433925857 84353895 2001100545 1548233367 

Wrong Answer. Your program's output doesn't match the expected output. You can try testing your code with custom input and try putting debug statements in your code.

Your submission failed for the following input:
A : [ 336465782, -278722862, -2145174067, 1101513929, 1315634022, -1369133069, 1059961393, 628175011, -1131176229, -859484421 ]
Your function returned the following :
1059961393 628175011 
The expected returned value :
1101513929 1315634022 



2 1 3 6 9
2 5