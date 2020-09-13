#include<iostream>
#include<vector>
using namespace std;

double median(vector<int>& nums, int i, int j)
{
	if((j - i + 1)%2 == 0)
		return((nums[(i+j)/2] + nums[(i+j)/2 + 1])/2.0);
	else
		return(nums[(i+j)/2]);
}

void printSubarray(vector<int>& nums, int i, int j)
{
	for(int c=i; c<=j; c++)
		printf("%d ", nums[c]);
	printf("\n");
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	// int m = nums1.size();
	// int n = nums2.size();
	
	// done = False;
	int i = 0, j = nums1.size()-1, p = 0, q = nums2.size()-1, m, n, k, l;
	double med1, med2;
	for(int c = 0; c<5; c++)
	{	
		printf("The sub arrays are\n");
		printSubarray(nums1,i,j);
		printSubarray(nums2,p,q);

		m = j-i+1;		// sizes
		n = q-p+1;		
		k = m/2<n/2?m/2:n/2; 

		
		// ------ termination condition when we have just 1 or 2 elements left --------- #
		if(m == 0)
		{
			if(n == 1)
				return(nums2[p]);
			else if(n == 2)
				return((nums2[p] + nums2[q])/2.0);
		}
		else if(n == 0)
		{
			if(m == 1)
				return(nums1[i]);
			else if(m == 2)
				return((nums1[i] + nums1[j])/2.0);
		}
		else if(m == 1 && n == 1)
			return((nums1[i] + nums2[p])/2.0);

		// ------ find individual medians -------- #

		med1 = median(nums1, i, j);
		med2 = median(nums2, p, q);

		printf("median %f %f\n", med1, med2);

		// ------ get rid of some elements ------ #

		if(med1 < med2 || (med1==med2 && nums1))
		{
			if(m == 1)
			{
				// we are left with only one array, const time from here on
				l = (p+q)/2;
				if(n%2 == 0)
					return( (nums1[i]<nums2[l]) ? nums1[i] : nums2[l]);
				else
				{
					if(nums1[i] < nums2[l-1])
						return((nums2[l-1]+nums2[l])/2.0);
					else
						return((nums1[i]+nums2[l])/2.0);
				}
			}
			else if(n == 1)
			{
				//we are left with only one array, const time from here on
				l = (i+j)/2;
				if(m%2 == 0)
					return( (nums2[p]>nums1[l]) ? nums2[p] : nums1[l]);
				else
				{
					if(nums2[p] > nums1[l+1])
						return((nums1[l-1]+nums1[l])/2.0);
					else
						return((nums1[l-1]+nums2[p])/2.0);
				}
			}
			else
			{
				i += k;
				q -= k;
			}
		}

		else
		{	
			// printf("flag1");
			if(m == 1)
			{
				// we are left with only one array, const time from here on
				l = (p+q)/2;
				if(n%2 == 0)
				{
					// printf("flag2\n");
					return( (nums1[i]>nums2[l+1]) ? nums1[0] : nums2[l+1]);
				}
				else
				{	
					// printf("flag3\n");
					if(nums1[i] > nums2[l+1])
					{
						// printf("flag");
						return((nums2[l]+nums2[l+1])/2.0);
					}
					else
						return((nums2[l]+nums1[i])/2.0);
				}
			}
			else if(n == 1)
			{
				//we are left with only one array, const time from here on
				l = (i+j)/2;
				if(m%2 == 0)
					return( (nums2[p]>nums1[l]) ? nums2[p] : nums1[l]);
				else
				{
					if(nums2[p] < nums1[l-1])
						return((nums1[l-1]+nums1[l])/2.0);
					else
						return((nums2[p]+nums1[l])/2.0);
				}
			}
			else
			{
				i -= k;
				q += k;
			}
		}




		 				// no. of elements to be eliminated from each

		// med1 = nums1[];
	}

	
	
	// otherwise recursion
	// k = (n+m)/2;	// no. of elements to be eliminated


	return(m+n);
}

int main()
{
	std::vector<int> nums1 = {1,3,5}, nums2 = {2,4,6,8};
	printf("%f\n", findMedianSortedArrays(nums1, nums2));
	
	return(0);
}