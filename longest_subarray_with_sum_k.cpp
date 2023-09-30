/*code studio*/
#include <bits/stdc++.h>
using namespace std;
// optimal only for positive elements

// int getLongestSubarray(vector<int>& nums, int k){
//     // Write your code here
//     int left=0;
//     int right=0;
//     int n=nums.size();
//     int maxlen=0;
//     int sum=0;
//     while(right<n)
//     {

//         while(left<=right&&sum >k)
//         {
//             sum=sum-nums[left];
//             left++;
//         }
//         if(sum==k)
//         {
//             maxlen=max(maxlen,right-left+1);
//         }
//         right++;
//         if(right<n)
//          sum=sum+nums[right];

//     }
//     return maxlen;
// }

// optimal  for both positive and negative

int getLongestSubarray(vector<int> &nums, int k)
{
    // Write your code here
    unordered_map<int, int> mp;
    int sum = 0;
    int maxlen = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum = sum + nums[i];
        if (sum == k)
        {
            maxlen = max(maxlen, i + 1);
        }
        int differ = sum - k;
        if (mp.find(differ) != mp.end())
        {
            maxlen = max(maxlen, i - mp[differ]);
        }
        if (mp.find(sum) == mp.end())
            mp[sum] = i;
    }
    return maxlen;
}