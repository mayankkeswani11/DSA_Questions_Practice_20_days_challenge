/**/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {

        //  we gonna take  3 variables that is totalSum for storing totalsum and currsum to keep track of sum of the current element
        int totalSum = 0;
        int currsum = 0;
        int maxlength = -1;
        // finding the total sum
        for (int i = 0; i < nums.size(); i++)
        {
            totalSum += nums[i];
        }
        // we gonna use the sliding window  apporach if the currsum is greater than equal to x then we gonna slide  the window
        int start = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            currsum += nums[i];
            while (start <= i && currsum > totalSum - x)
            {
                currsum = currsum - nums[start++];
            }
            if (currsum == totalSum - x)
            {
                maxlength = max(maxlength, i - start + 1);
            }
        }
        if (maxlength == -1)
        {
            return -1;
        }
        return nums.size() - maxlength;
    }
};