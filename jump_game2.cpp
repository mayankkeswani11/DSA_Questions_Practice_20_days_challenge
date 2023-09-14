/*You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].



Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2*/

#include <bits/stdc++.h>
using namespace std;
int jump(vector<int> &nums)
{
    // int count=0;
    // vector<int> dp(nums.size(),-1);
    // dp[0]=nums[0];
    // for(int i=1;i<nums.size();i++)
    // {
    //     if(dp[i-1]>0)
    //     {
    //         dp[i]=max(dp[i-1]-1,nums[i]);
    //         if(dp[i]>dp[i-1])
    //         {
    //             count++;
    //         }
    //     }

    // }
    // return count;

    int count = 0;
    int n = nums.size();
    int temp = n;
    int i = 0;
    if (n == 1)
    {
        return 0;
    }
    while (1)
    {
        if ((nums[i] + i + 1) >= temp)
        {
            temp = i + 1;
            count++;
            i = 0;
        }
        else
        {
            i++;
        }
        if (temp == 1)
        {
            break;
        }
    }
    return count;
}
int main()
{
    vector<int> arr = {3, 2, 1, 2, 1};
    cout << jump(arr);
}