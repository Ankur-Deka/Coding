#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main()
{
	int n;
	printf("Enter the size of the array\n");
	scanf("%d", &n);
	// int arr[n];
	int *arr = (int*) malloc(n*sizeof(int));
	printf("Enter the array elements\n");
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	printf("The array is: [");
	for(int i = 0; i < n; i++)
		printf(" %d", arr[i]);
	printf(" ]\n");
	return 0;
}


Wrong Answer. Your program's output doesn't match the expected output. You can try testing your code with custom input and try putting debug statements in your code.

Your submission failed for the following input:
A : [ 4, 8, -7, -5, -13, 9, -7, 8 ]
B : [ 4, -15, -10, -3, -13, 12, 8, -8 ]
Your function returned the following :
90
The expected returned value :
108