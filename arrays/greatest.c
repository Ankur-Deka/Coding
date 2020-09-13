#include<stdio.h>
#include<stdlib.h>

/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output string. Make sure the string ends with null character
 */
 
double powr(int n)
{
    int i;
    double x=1;
    for(i = 0; i<n; i++)
        x*=10;
    return(x);
}

int numDigits(int a)
{
    if(a==0)
        return(1);
    int i = 0;
    while(a>0)
    {
           a /= 10; i++;
    }
    return(i);
}
int greater(int a, int b)
{
    int i = 1, numD1, numD2; 
    double x, y;

    numD1 = numDigits(a);
    numD2 = numDigits(b);

    x = a*powr(numD2)+b;
    y = b*powr(numD1)+a;

    if(x>=y)
        return(0);
    else
        return(1);
}

void merge(int *A, int lenA, int *B, int lenB)
{
    int i = 0, j = 0, k = 0;
    int *C = (int*) malloc((lenA+lenB)*sizeof(int));
    while(i<lenA && j<lenB)
    {
        if(A[i]<=B[j])
            C[k++] = A[i++];
        else
            C[k++] = B[j++];
    }
    while(i<lenA)
        C[k++] = A[i++];
    while(j<lenB)
        C[k++] = A[j++];
    
    for(i = 0; i< lenA+lenB; i++)
        A[i] = C[i];
}

void sort(int *A, int len)
{
    if(len>1)
    {
        sort(A, len/2);
        sort(A+len/2, len-len/2);
        merge(A, len/2, A+len/2, len-len/2);
    }
}

char* largestNumber(const int* A, int n1) {
    int i, j, k, temp, max, maxLoc,  totDigits = 0;
    int *B = (int*) malloc(n1*sizeof(int));
    double sum = 0;
    for(i = 0; i<n1; i++)
    {
        B[i] = A[i];
        // compute number of digits
        totDigits += numDigits(B[i]);
        sum += B[i];
    }

    if(sum == 0)
        return("0");

    sort(B, n1);
    char* arr = (char*) malloc((totDigits+1)*sizeof(char));
    // convert to string
    k = 0;
    for(i = 0; i<n1; i++)
    {
        temp = numDigits(B[i]);
        for(j = temp-1; j>=0; j--)
        {
            arr[k+j] = B[i]%10+'0';
            B[i]/=10;
        }
        k+=temp;
    }
    arr[totDigits] = '\0';
    return(arr);

}


int main()
{
    const int A[] = {8, 89};
    int n1 = 2;
    // printf("%d\n", numDigits(31));
    printf("%s", largestNumber(A, n1));
    return(0);
}











// Correctness
// Wrong Answer. Your program's output doesn't match the expected output. You can try testing your code with custom input and try putting debug statements in your code.

// Your submission failed for the following input:
// A : [ 8, 89 ]
// Your function returned the following :

// The expected returned value :
// 898