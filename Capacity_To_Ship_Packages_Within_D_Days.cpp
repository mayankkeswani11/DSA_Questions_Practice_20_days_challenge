#include <bits/stdc++.h>
using namespace std;
// brute force solution time-O(n2)

// int calculate(vector<int> &weights,int cap)
// {
//     int days=1;
//     int load=0;
//     for(int i=0;i<weights.size();i++)
//     {
//         if(load+weights[i]>cap)
//         {
//             days+=1;
//             load=weights[i];
//         }
//         else{
//             load+=weights[i];
//         }
//     }
//     return days;

// }

// int leastWeightCapacity(vector<int> &weights, int d)
// {
//     // Write your code here.
//     int sum=0;
//     for(int i=0;i<weights.size();i++)
//     {
//         sum=sum+weights[i];
//     }
//     int maxi=0;
//     for(int i=0;i<weights.size();i++)
//     {
//         maxi=max(maxi,weights[i]);
//     }
//     for(int i=maxi;i<=sum;i++)
//     {
//         int ans=calculate(weights,i);
//         if(calculate(weights,i)<=d)
//         {
//             return i;
//         }
//     }
// }

// optimal binary search O(nlogn)
int calculate(vector<int> &weights, int cap)
{
    int days = 1;
    int load = 0;
    for (int i = 0; i < weights.size(); i++)
    {
        if (load + weights[i] > cap)
        {
            days += 1;
            load = weights[i];
        }
        else
        {
            load += weights[i];
        }
    }
    return days;
}

int leastWeightCapacity(vector<int> &weights, int d)
{
    // Write your code here.
    int sum = 0;
    for (int i = 0; i < weights.size(); i++)
    {
        sum = sum + weights[i];
    }
    int maxi = 0;
    for (int i = 0; i < weights.size(); i++)
    {
        maxi = max(maxi, weights[i]);
    }
    int low = maxi;
    int high = sum;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (calculate(weights, mid) <= d)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}