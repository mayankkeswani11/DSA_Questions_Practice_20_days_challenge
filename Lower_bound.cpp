/*code studio question */ 

#include<bits/stdc++.h>
using namespace std;
// int lowerBound(vector<int> arr, int n, int x) {
// 	// Write your code here
// 	int low=0;
// 	int high=n-1;
// 	int ans=0;
// 	while(low<=high)
// 	{
// 		int mid=(low+high)/2;
// 		if(arr[mid]>=x)
// 		{
// 			ans=mid;
// 			high=mid-1;
// 		}
// 		else{
			
// 			low=mid+1;
// 			ans=low;
// 		}
// 	}
// 	return ans;
// }
int lowerBound(vector<int> arr, int n, int x) {
	// Write your code here
	int low=0;
	int high=n-1;
	int ans=0;
	while(low<=high)
	{
		int mid=(low+high)/2;
		if(arr[mid]==x)
		{
			ans=mid;
			high=mid-1;
		}
		else{
			if(arr[mid]>x)
			{
				ans=mid;
				high=mid-1;
			}
			else{
				low=mid+1;
				ans=low;
			}
			
			
		}
	}
	return ans;
}
