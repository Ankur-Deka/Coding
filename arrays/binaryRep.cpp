	#include<stdio.h>
	#include<string>
	using namespace std;

	string findDigitsInBinary(int A)
	{
		if(A==0)
		{
			return(to_string(0));
		}
		string s;
		int digit;
		while(A!=0)
		{	
			digit = A%2;
			A = A/2;
			s.insert(0, to_string(digit));
		}
		return(s);
	}

	int main()
	{
		string a = findDigitsInBinary(0);
		printf("%s\n", a.c_str());
		return(0);
	}