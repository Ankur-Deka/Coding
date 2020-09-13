#include<stdio.h>
#include<string.h>

struct person
{
	char name[20];
	int age;
};

int main()
{
	person p1=
	{
		"Ankur", 23
	};
	printf("p1: %s, %d\n", p1.name, p1.age);

	// creating an array of structures
	person perArr[10];
	perArr[0].age = 22;
	strcpy(perArr[0].name, "sushmita");
	printf("p2: %d, %s\n", perArr[0].age, perArr[0].name);
	
	return 0;

}