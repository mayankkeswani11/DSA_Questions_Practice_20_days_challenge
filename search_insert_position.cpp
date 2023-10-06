// int searchInsert(vector<int>& arr, int x)
// {
// 	// Write your code here.
// 	int low=0;
// 	int n=arr.size();
// 	int high=n-1;
// 	int ans=0;
// 	while(low<=high)
// 	{
// 		int mid=(low+high)/2;
// 		if(arr[mid]==x)
// 		{
// 			return mid;
// 		}
// 		else{
// 			if(arr[mid]>x)
// 			{
// 				ans=mid;
// 				high=mid-1;
// 			}
// 			else{
// 				low=mid+1;
// 				ans=low;
// 			}

// 		}
// 	}
// 	return ans;
// }
#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int> &arr, int x)
{
    // Write your code here
    int low = 0;
    int n = arr.size();
    int high = n - 1;
    int ans = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {

            low = mid + 1;
            ans = low;
        }
    }
    return ans;
}