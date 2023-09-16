#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                            long long int n, long long int k);

int main()
{
    long long int t, i;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}

vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, long long int K)
{

    vector<long long> ans;

    deque<long long int> ls;
    for (int i = 0; i < K; i++)
    {
        if (A[i] < 0)
        {
            ls.push_back(i);
        }
    }
    if (ls.size() > 0)
    {
        ans.push_back(A[ls.front()]);
    }
    else
    {
        ans.push_back(0);
    }

    for (int i = K; i < N; i++)
    {
        if (!ls.empty() && i - ls.front() >= K)
        {
            ls.pop_front();
        }

        if (A[i] < 0)
        {
            ls.push_back(i);
        }
        if (ls.size() > 0)
        {
            ans.push_back(A[ls.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }
    return ans;
}