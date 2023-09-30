// code studio

#include <bits/stdc++.h>
using namespace std;

// brute force solution

// int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
//     // Write Your Code Here
//     int cnt=0;
//     for(int i=0;i<arr.size();i++)
//     {
//         int sum=0;
//         for(int j=i;j<arr.size();j++)
//         {
//             sum=sum+arr[j];
//             if(sum==k)
//             {
//                 cnt++;
//             }
//         }
//     }
//     return cnt;
// }

// optimal solution

int findAllSubarraysWithGivenSum(vector<int> &arr, int k)
{
    // Write Your Code Here
    int cnt = 0;
    int sum = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        sum = sum + arr[i];
        int differ = sum - k;
        cnt = cnt + mp[differ];
        mp[sum]++;
    }
    return cnt;
}