
#include <bits/stdc++.h>
using namespace std;
int merge(vector<int> &arr, int start, int mid, int end)
{
    vector<int> temp;
    int left = start;
    int right = mid + 1;
    int cnt = 0;
    int k = start;
    int i = 0;
    int j = 0;
    while (left <= mid && right <= end)
    {
        /* code */
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            cnt += mid - left + 1;
            right++;
        }
    }
    while (left <= mid)
    {
        /* code */
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= end)
    {
        /* code */
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = start; i <= end; i++)
    {
        /* code */
        arr[i] = temp[i - start];
    }

    return cnt;
}
int merge_sort(vector<int> &arr, int start, int end)
{
    int cnt = 0;
    if (start >= end)
    {
        return cnt;
    }
    int mid = (start + end) / 2;
    cnt += merge_sort(arr, start, mid);
    cnt += merge_sort(arr, mid + 1, end);
    cnt += merge(arr, start, mid, end);
    return cnt;
}
int main()
{
    vector<int> arr ={2, 5, 1, 3, 4};
    int n = arr.size();

    cout << merge_sort(arr, 0, n - 1);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
        /* code */
    }
}