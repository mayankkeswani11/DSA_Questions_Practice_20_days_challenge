//code studio problem
#include <bits/stdc++.h>
using namespace std;
// int subarraysXor(vector<int> &arr, int x)
// {
//     //    Write your code here.
//     //brute force solution 
//     int cnt=0;
//     for(int i=0;i<arr.size();i++)
//     {
//         for(int j=i;j<arr.size();j++)
//         {
//             int xr=0;
//             for(int k=i;k<=j;k++)
//             {
//                 xr=xr^arr[k];
//             }
//             if(xr==x)
//             {
//                 cnt++;
//             }
//         }
//     }
//     return cnt;
// }

//better solution

// int subarraysXor(vector<int> &arr, int x)
// {
//     //    Write your code here.
//     //better solution 
//     int cnt=0;
//     for(int i=0;i<arr.size();i++)
//     {
//         int xr=0;
//         for(int j=i;j<arr.size();j++)
//         {
//             xr=xr^arr[j];
//             if(xr==x)
//             {
//                 cnt++;
//             }
//         }
//     }
//     return cnt;
// }


//optimal solution 
int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    
    int cnt=0;
    map<int,int> mp;
    mp[0]=1;
    int xr=0;
    for(int i=0;i<arr.size();i++)
    {
        xr=xr^arr[i];
        int y=xr^x;
        cnt=cnt+mp[y];
        mp[xr]++;
    }
    return cnt;
}