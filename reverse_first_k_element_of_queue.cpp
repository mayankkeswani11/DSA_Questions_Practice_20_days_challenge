#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0)
        {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty())
        {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}

queue<int> modifyQueue(queue<int> q, int k)
{
    stack<int> st;
    int n = k;
    while (n--)
    {
        int val = q.front();
        q.pop();
        st.push(val);
    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    n = q.size() - k;
    while (n--)
    {
        int val = q.front();
        q.pop();
        q.push(val);
    }
    return q;
}