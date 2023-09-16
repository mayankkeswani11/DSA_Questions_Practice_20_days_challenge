#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> rearrangeQueue(queue<int> &q)
    {
        vector<int> ans;
        int n = q.size();
        stack<int> st;
        for (int i = 0; i < n / 2; i++)
        {
            st.push(q.front());
            q.pop();
        }
        while (!st.empty())
        {
            q.push(st.top());
            st.pop();
        }
        for (int i = 0; i < n / 2; i++)
        {
            int val = q.front();
            q.pop();
            q.push(val);
        }
        for (int i = 0; i < n / 2; i++)
        {
            st.push(q.front());
            q.pop();
        }
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
            int val = q.front();
            q.pop();
            ans.push_back(val);
        }
        return ans;
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        vector<int> ans = ob.rearrangeQueue(q);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
