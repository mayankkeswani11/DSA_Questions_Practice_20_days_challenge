
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int size1 = nums1.size();
        int size2 = nums2.size();

        vector<int> num;
        int i = 0;
        int j = 0;
        while (i < size1 && j < size2)
        {
            if (nums1[i] < nums2[j])
            {
                num.push_back(nums1[i]);
                i++;
            }
            else
            {
                num.push_back(nums2[j]);
                j++;
            }
        }
        while (i < size1)
        {
            num.push_back(nums1[i]);
            i++;
        }
        while (j < size2)
        {
            num.push_back(nums2[j]);
            j++;
        }
        double ans = 0;
        int n = num.size();
        if (n % 2 == 0)
        {
            ans = (num[n / 2 - 1] + num[(n / 2)]) / 2.0;
        }
        else
        {
            return num[n / 2];
        }
        return ans;
    }
};
// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         double x;
//         for(int i=0;i<nums2.size();i++)
//         {
//             nums1.push_back(nums2[i]);
//         }
//         sort(nums1.begin(),nums1.end());
//         int n=nums1.size();
//             if(n%2==0)
//             {
//                 x=(nums1[(n/2)-1]+nums1[n/2])/2.0;

//             }
//             else{
//                 x=nums1[n/2];
//             }
//              return x;

//     }
// };