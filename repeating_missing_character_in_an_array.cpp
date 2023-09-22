/*Code studio problem*/
#include <bits/stdc++.h>
using namespace std;

pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    n = (long long)n;
    // Write your code here
    long long SN = (n * (n + 1)) / 2;
    long long SN2 = (n * (n + 1) * (2 * n + 1)) / 6;

    long long s1 = 0;
    long long s2 = 0;
    for (int i = 0; i < n; i++)
    {
        s1 += (long long)arr[i];
        s2 += (long long)arr[i] * (long long)arr[i];
    }

    long long val1 = s1 - SN;
    long long val2 = s2 - SN2;
    val2 = (long long)val2 / val1;

    long long x = (val1 + val2) / 2;

    long long y = x - val1;

    return {(int)y, (int)x};
}
