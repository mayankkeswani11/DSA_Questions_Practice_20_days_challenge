/*You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 105*/

#include <bits/stdc++.h>
using namespace std;
bool canJump(vector<int> &nums)
{
    // 1st approach

    // int j=0;
    // for(int i=0;i<nums.size();i++)
    // {
    //     if(j<i)
    //     {
    //         return false;
    //     }
    //     j=max(j,i+nums[i]);
    // }
    // return true;

    // 2nd approach

    // vector<int> dp(nums.size());
    // dp[0]=nums[0];
    // for(int i=1;i<nums.size();i++)
    // {
    //     if(dp[i-1]>0)
    //     {
    //         dp[i]=max(dp[i-1]-1,nums[i]);
    //     }
    //     else{
    //         return false;
    //     }

    // }
    // if(dp[dp.size()-1]!=-1)
    // {
    //     return  true;
    // }
    // return false;

    // 3rd aprroach

    int n = nums.size() - 1;
    int last_position = n;
    for (int i = n; i >= 0; i--)
    {
        if (nums[i] + i >= last_position)
        {
            last_position = i;
        }
        if (last_position == 0)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    vector<int> arr = {3, 2, 1, 2, 1};
    if (canJump(arr))
    {
        cout << "yes you can";
    }
    else
    {
        cout << "not at all";
    }
    return 0;
}