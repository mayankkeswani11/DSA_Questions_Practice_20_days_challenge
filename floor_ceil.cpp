#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr, int n, int x)
{
    // Write your code here
    int low = 0;
    int high = n - 1;
    int ans = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] <= x)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}
int upperBound(vector<int> &arr, int x, int n)
{
    // Write your code here.
    int low = 0;
    int high = n - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
            ans = low;
        }
    }
    return ans;
}
pair<int, int> getFloorAndCeil(vector<int> &arr, int n, int x)
{
    // Write your code here.
    if (lowerBound(arr, n, x) == -1)
    {
        return {-1, -1};
    }
    cout << lowerBound(arr, n, x);
    // pair<int,int> pr=make_pair(lowerBound(arr, n, x),upperBound(arr, x,n));
}
int main()
{
    vector<int> arr = {3, 4, 4, 6, 8, 9};
    int n = 6;
    int x = 8;
    getFloorAndCeil(arr, n, x);
}
