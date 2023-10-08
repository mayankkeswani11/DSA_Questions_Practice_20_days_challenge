bool possible(vector<int> arr, int day, int k, int m)
{
    int cnt = 0;
    int number_of_bokeey = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] <= day)
        {
            cnt += 1;
        }
        else
        {
            number_of_bokeey += (cnt / k);
            cnt = 0;
        }
    }
    number_of_bokeey += (cnt / k);
    if (number_of_bokeey >= m)
    {
        return true;
    }
    return false;
}
// brute force solution

// int roseGarden(vector<int> arr, int k, int m)
// {
// 	// Write your code here
// 	if(arr.size()<(k*m))
// 	{
// 		return -1;
// 	}
// 	int mini=INT_MAX;
// 	int maxi=INT_MIN;
// 	for(int i=0;i<arr.size();i++)
// 	{
// 		mini=min(mini,arr[i]);
// 	}
// 	for(int i=0;i<arr.size();i++)
// 	{
// 		maxi=max(maxi,arr[i]);
// 	}
// 	for(int i=mini;i<=maxi;i++)
// 	{
// 		if(possible(arr,i,k,m)==true)
// 		{
// 			return i;
// 		}
// 	}

// }

//  optimal binary search solution

int roseGarden(vector<int> arr, int k, int m)
{
    // Write your code here
    if (arr.size() < (k * m))
    {
        return -1;
    }
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        mini = min(mini, arr[i]);
    }
    for (int i = 0; i < arr.size(); i++)
    {
        maxi = max(maxi, arr[i]);
    }
    int low = mini;
    int high = maxi;
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (possible(arr, mid, k, m) == true)
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
