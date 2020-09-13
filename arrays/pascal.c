#include<stdio.h>


int main()
{
	int cont = 1, n, i, j;
	while(cont)
	{
		printf("\tWelcome to Pascal's triangle printer\n\tEnter the level\n\t");
		scanf("%d", &n);
		int arr[n];
		arr[n-1] = 1;
		for(i = n-1; i>=0; i--)
		{
			// printf("\n\t");
			arr[i] = 1;
			// printf("%d ", arr[i]);
			for(j = i+1; j<n-1; j++)
			{
				arr[j] += arr[j+1];
				// printf("%d ", arr[j]);
			}
			if(i!=n-1)
				arr[0] = arr[0];
				// printf("%d ", arr[n-1]);
		}
		printf("\n\tWould you like to print another Pascal's triangle?\n\t1:Yes\n\t0:No\n\t");
		scanf("%d", &cont);
	}
	return(0);
}