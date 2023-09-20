/*Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.



Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]


Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        //     vector<int> answer;
        //     int product=1;
        //     for(int i=0;i<nums.size();i++)
        //     {
        //         product=1;
        //         for(int j=0;j<nums.size();j++)
        //         {
        //             if(i!=j)
        //             {
        //                 product=product*nums[j];
        //             }
        //         }
        //         answer.push_back(product);
        //     }
        //     return answer;
        // }

        // 2nd appproach of this problem
        //  int n=nums.size();
        //  vector<int> prefix1(n);
        //  vector<int> prefix2(n);

        // vector<int> answer;
        // prefix1[0]=1;
        // for(int i=1;i<nums.size();i++)
        // {
        //     prefix1[i]=prefix1[i-1]*nums[i-1];
        // }
        //  prefix2[n-1]=1;
        // for(int j=n-2;j>=0;j--)
        // {
        //     prefix2[j]=prefix2[j+1]*nums[j+1];
        // }
        // for(int i=0;i<nums.size();i++)
        // {
        //     answer.push_back(prefix1[i]*prefix2[i]);
        // }
        // return answer;
        // }

        // 3rd approach of this problem

        int n = nums.size();
        vector<int> answer(n);

        answer[0] = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            answer[i] = answer[i - 1] * nums[i - 1];
        }
        int r = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            answer[i] = answer[i] * r;
            r = r * nums[i];
        }
        return answer;
    }
};