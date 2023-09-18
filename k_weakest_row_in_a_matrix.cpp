/*You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of all the 0's in each row.

A row i is weaker than a row j if one of the following is true:

The number of soldiers in row i is less than the number of soldiers in row j.
Both rows have the same number of soldiers and i < j.
Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.



Example 1:

Input: mat =
[[1,1,0,0,0],
 [1,1,1,1,0],
 [1,0,0,0,0],
 [1,1,0,0,0],
 [1,1,1,1,1]],
k = 3
Output: [2,0,3]
Explanation:
The number of soldiers in each row is:
- Row 0: 2
- Row 1: 4
- Row 2: 1
- Row 3: 2
- Row 4: 5
The rows ordered from weakest to strongest are [2,0,3,1,4].
Example 2:

Input: mat =
[[1,0,0,0],
 [1,1,1,1],
 [1,0,0,0],
 [1,0,0,0]],
k = 2
Output: [0,2]
Explanation:
The number of soldiers in each row is:
- Row 0: 1
- Row 1: 4
- Row 2: 1
- Row 3: 1
The rows ordered from weakest to strongest are [0,2,3,1].


Constraints:

m == mat.length
n == mat[i].length
2 <= n, m <= 100
1 <= k <= m
matrix[i][j] is either 0 or 1.*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        // //brute force solution
        // //step1 we need to count every soldier in a row and put it int pair of set with its index and count
        // int count =0;
        // int cnt=0;
        // vector<int> ans;
        // set<pair<int,int>> pr;
        // for(int i=0;i<mat.size();i++)
        // {
        //     for(int j=0;j<mat[0].size();j++)
        //     {
        //         if(mat[i][j]==1)
        //         {
        //             count++;
        //         }
        //     }
        //     pr.insert({count,i});
        //     count=0;
        // }
        // //step2--> append first k indexs in an ans array
        // for(auto it:pr)
        // {
        //     if(k!=0)
        //     {
        //         ans.push_back(it.second);
        //         k--;
        //     }
        // }
        // return ans;

        // better approach without using space

        vector<int> sums;
        vector<int> ans;
        for (int i = 0; i < mat.size(); i++)
        {
            int sum = 0;
            for (int j = 0; j < mat[0].size(); j++)
            {
                sum = sum + mat[i][j];
            }
            sums.push_back(sum);
        }

        for (int i = 0; i < k; i++)
        {
            int mini = sums[0];
            int index = 0;
            for (int j = 0; j < mat.size(); j++)
            {
                if (mini > sums[j])
                {
                    mini = sums[j];
                    index = j;
                }
            }
            ans.push_back(index);
            sums[index] = INT_MAX;
        }
        return ans;
    }
};