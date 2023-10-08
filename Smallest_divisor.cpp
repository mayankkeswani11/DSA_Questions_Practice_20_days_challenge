#include <bits/stdc++.h>
using namespace std;
bool possible(vector<int> &arr, int divisor, int limit)
{
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        double temp = arr[i] / (double)divisor;
        ans = ans + ceil(temp);
        if (ans > limit)
        {
            return false;
        }
    }
    return true;
}

int smallestDivisor(vector<int> &arr, int limit)
{
    // Write your code here.
    int mini = INT_MAX;
    int maxi = INT_MIN;
    // for(int i=0;i<arr.size();i++)
    // {
    // 	mini=min(mini,arr[i]);
    // }
    for (int i = 0; i < arr.size(); i++)
    {
        maxi = max(maxi, arr[i]);
    }
    int low = 1;
    int high = maxi;
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (possible(arr, mid, limit) == true)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}