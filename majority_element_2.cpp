/*Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.



Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]


Constraints:

1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109*/

#include <bits/stdc++.h>
using namespace std;
vector<int> majorityElement(vector<int> &nums)
{
    // vector<int> arr;
    // unordered_map<int,int> mp;
    // for(int i=0;i<nums.size();i++)
    // {
    //     mp[nums[i]]++;
    // }
    // for(auto it:mp)
    // {
    //     if(it.second>(nums.size()/3))
    //     {
    //         arr.push_back(it.first);
    //     }
    // }
    // return arr;

    // second apporaoch

    // int count1=0;
    // int count2=0;
    // int num1=INT_MIN;
    // int num2=INT_MIN;
    // for(auto el:nums)
    // {
    //     if(num1==el)
    //     {
    //         count1++;
    //     }
    //     else if(num2==el)
    //     {
    //         count2++;
    //     }
    //     else if(count1==0)
    //     {
    //         num1=el;
    //         count1=1;
    //     }
    //     else if(count2==0)
    //     {
    //             num2=el;
    //             count2=1;
    //     }
    //     else{
    //             count1--;
    //             count2--;
    //         }

    // }
    // count1=0;
    // count2=0;
    // for(int i=0;i<nums.size();i++)
    // {
    //     if(nums[i]==num1)
    //     {
    //         count1++;
    //     }
    //     else{
    //         if(nums[i]==num2)
    //         {
    //             count2++;
    //         }
    //     }
    // }
    // vector<int> arr;
    // if(count1>(nums.size()/3))
    // {
    //     arr.push_back(num1);
    // }
    // if(count2>(nums.size()/3))
    // {
    //     arr.push_back(num2);
    // }
    // return arr;
}