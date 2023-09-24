// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

// Example 1:

// Input: nums = [3,2,3]
// Output: 3
// Example 2:

// Input: nums = [2,2,1,1,1,2,2]
// Output: 2

// Constraints:

// n == nums.length
// 1 <= n <= 5 * 104
// -109 <= nums[i] <= 109

// Follow-up: Could you solve the problem in linear time and in O(1) space?

#include <bits/stdc++.h>
using namespace std;
int majorityElement(vector<int> &nums)
{
    // brute force

    // set<int> arr(nums.begin(),nums.end());
    // set<int>::iterator x;
    // int sum=INT_MIN;
    // int count=0;
    // int var;
    // for(x=arr.begin();x!=arr.end();x++)
    // {
    //     count=0;
    //     for(int i=0;i<nums.size();i++)
    //     {
    //         if(*x==nums[i])
    //         {
    //             count++;
    //         }
    //     }
    //     if(count>sum)
    //     {
    //         sum=count;
    //         var=*x;
    //     }
    // }
    // return var;




    // unordered_map<int,int> mp;
    // int n=nums.size();
    // for(int i=0;i<n;i++)
    // {
    //     mp[nums[i]]++;
    // }

    // int ans;
    // for(auto it:mp)
    // {
    //     if(it.second>(n/2))
    //     {
    //         ans=it.first;
    //         break;
    //     }
    // }
    // return ans;

    int element;
    int cnt = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (cnt == 0)
        {
            cnt = 1;
            element = nums[i];
        }
        else
        {
            if (element == nums[i])
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }
    }

    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (element == nums[i])
        {
            cnt++;
        }
    }
    if (cnt > (n / 2))
    {
        return element;
    }
    return -1;
}