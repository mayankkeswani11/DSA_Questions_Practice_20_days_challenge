#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int area = 0;
        int i = 0;
        int j = height.size() - 1;
        while (i < j)
        {
            int wt = j - i;
            int ht = min(height[i], height[j]);
            area = max(area, wt * ht);
            if (height[i] <= ht)
            {
                i++;
            }
            if (height[j] <= ht)
            {
                j--;
            }
        }
        return area;
    }
};
int main()
{
    vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution s;
    cout << s.maxArea(heights);
}