#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isAnagram(vector<int> count1, vector<int> count2)
    {
        bool flag = true;
        for (int i = 0; i < 26; i++)
        {
            if (count1[i] != count2[i])
            {
                flag = false;
                break;
            }
        }
        return flag;
    }
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ans;
        if (p.size() > s.size())
        {
            return ans;
        }
        vector<int> count1(26, 0);
        vector<int> count2(26, 0);

        for (int i = 0; i < p.size(); i++)
        {
            count1[p[i] - 'a']++;
        }

        // store the first window count in count2
        for (int i = 0; i < p.size(); i++)
        {
            count2[s[i] - 'a']++;
        }
        // check for the first window

        if (isAnagram(count1, count2))
        {
            ans.push_back(0);
        }
        // check for another window

        int index;
        int i = p.size();
        int n = s.size();
        int start = 0;
        while (i < n)
        {
            index = s[i] - 'a';
            count2[index]++;
            count2[s[start] - 'a']--;
            start++;
            if (isAnagram(count1, count2))
            {
                ans.push_back(start);
            }
            i++;
        }
        return ans;
    }
};
// class Solution {
// public:
//     vector<int> findAnagrams(string s, string p) {
//         vector<int> ans;
//         vector<int> hash(26);
//         vector<int> temp(26);
//         for(int i=0;i<p.size();i++)
//         {
//             hash[p[i]-'a']++;
//         }
//         int head=0;
//         int tail=0;
//         while(head<s.size())
//         {
//             if(temp==hash)
//             {
//                 ans.push_back(tail);
//             }
//              while(head-tail+1>p.size())
//                 {
//                     temp[s[tail]-'a']--;
//                     tail++;
//                 }
//                 temp[s[head]-'a']++;
//                 head++;

//         }
//         if(temp==hash)
//         {
//             ans.push_back(tail);

//         }
//         return ans;

//     }
// };