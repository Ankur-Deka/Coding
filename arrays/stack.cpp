#include<stdio.h>
#include<stack>
using namespace std;

struct person
{	
 	float height = 5;
 	int age = 20;
}ankur, sushmita;

int main()
{
	// testing integer stack
	stack<int> myStack;
	bool end = 0;
	printf("%d\n", myStack.empty());
	myStack.push(20);
	printf("%d\n", myStack.empty());
	int num = myStack.top();
	printf("%d\n", num);
	
	// testing person stack
	stack<person> perStack;
	ankur.age = 23;
	ankur.height = 5.5;
	perStack.push(ankur);
	perStack.push(sushmita);
	while(!perStack.empty())
	{
		printf("Age and Height %d, %0.1f\n", perStack.top().age, perStack.top().height);
		perStack.pop();
	}
	return(0);
}