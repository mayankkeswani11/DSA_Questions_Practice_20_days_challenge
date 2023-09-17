#include <bits/stdc++.h>
using namespace std;
bool compare(vector<int> count1, vector<int> count2)
{
    for (int i = 0; i < 26; i++)
    {
        if (count1[i] != count2[i])
        {
            return false;
        }
    }
    return true;
}
bool checkInclusion(string s1, string s2)
{
    // step1 store count of first string int count1 array

    vector<int> count1(26, 0);
    for (int i = 0; i < s1.length(); i++)
    {
        int index = s1[i] - 'a';
        count1[index]++;
    }

    // step2 check the first window of string 2 first we need to find the count of first window in string 2 and compare it with count of string s1 and window size is obviously length of first string because it is a substring

    vector<int> count2(26, 0);
    int i = 0;
    int k = s1.length();   // window size or string 1 size
    int len = s2.length(); // string 2 size
    while (i < k && i < len)
    {
        int index = s2[i] - 'a';
        count2[index]++;
        i++;
    }
    // comapring first window with string s1
    if (compare(count1, count2))
    {
        return true;
    }

    // if first window is not same and check for the other

    while (i < len)
    {
        int index = s2[i] - 'a';
        count2[index]++;
        index = s2[i - k] - 'a'; // if you are checking the another char to be same then first remove initial char of previous substring
        count2[index]--;
        i++;
        if (compare(count1, count2))
        {
            return true;
        }
    }
    return false;
}
;

/*this code gives you memory limit exceeded it is only valid for small string*/
/*
// class Solution {
// public:

// void solve(string &str,vector<string> &ans,int index)
// {
//     if(index>=str.size())
//     {
//         ans.push_back(str);
//         return;
//     }

//     for(int i=index;i<str.length();i++)
//     {
//         swap(str[index],str[i]);
//         solve(str,ans,index+1);
//         swap(str[index],str[i]);
//     }
// }

// vector<string> generatePermutations(string &str)
// {
//      vector<string> ans;
//     if(str.size()==0)
//     {
//         return ans;
//     }

//     int index=0;
//     solve(str,ans,index);
//     // sort(ans.begin(),ans.end());
//     return ans;
// }

//     bool checkInclusion(string s1, string s2) {
//         vector<string>ans=generatePermutations(s1);

//         for(int i=0;i<ans.size();i++)
//         {
//             bool isFound = s2.find(ans[i]) != string::npos;
//             if(isFound)
//             {
//                 return true;
//             }
//         }
//         return false;
//     }
// };
*/