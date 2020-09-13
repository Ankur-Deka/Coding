#include<stdio.h>
#include<stdlib.h>

void merge(int *a, int lena, int*b, int lenb, int *tempArr)
{
    int i = 0, j = 0, k = 0;
    while(i<lena || j<lenb)
    {
        if(i == lena)
            tempArr[k++] = b[j++];
        else if(j==lenb)
            tempArr[k++] = a[i++];
        else if(a[i]<=b[j])
            tempArr[k++] = a[i++];
        else
            tempArr[k++] = b[j++];
    }
    for(k = 0; k < lena+lenb; k++)
        a[k] = tempArr[k];
}

void sort(int *arr, int len, int *tempArr)
{
    if(len>1)
    {
        int len1 = len/2; int len2 = len - len1;
        sort(arr, len1, tempArr);
        sort(arr+len1, len2, tempArr);
        merge(arr, len1, arr+len1, len2, tempArr);
    }
}


int hotel(int* arrive, int n1, int* depart, int n2, int K)
{
    int i;
    int *tempArr = (int*) malloc((n1+n2)*sizeof(int));
    void sort(arrive, n1, tempArr);
    void sort(depart, n2, tempArr);
    return(arrive[0]);
}

int main()
{
    int a[] = {9,6,3}, b[] = {8,5,2}, n1 = 3, i;
    i = hotel(a, n1, b, n1, 1);
    printf("%d", i);
    return(0);
}
