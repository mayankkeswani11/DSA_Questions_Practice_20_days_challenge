
// Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

// Return any possible rearrangement of s or return "" if not possible.

 

// Example 1:

// Input: s = "aab"
// Output: "aba"
// Example 2:

// Input: s = "aaab"
// Output: ""
 

// Constraints:

// 1 <= s.length <= 500
// s consists of lowercase English letters.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // string reorganizeString(string s) {
    //     int count[26]={0};
    //     int n=s.size();
    //     int maxlen=0;
    //     int index;
    //     for(int i=0;i<s.size();i++)
    //     {
    //         count[s[i]-'a']++;
    //     }

    //     for(int i=0;i<26;i++)
    //     {
    //         if(count[i]>maxlen)
    //         {
    //             maxlen=count[i];
    //             index=i;
    //         }
    //     }
    //     if(maxlen>(n+1)/2)
    //     {
    //         return "";
    //     }
    //     char arr[n];
    //     int ind=0;
    //     while(count[index]>0)
    //     {
    //         arr[ind]='a'+index;
    //         ind+=2;
    //         count[index]--;
    //     }

    //     for(int i=0;i<26;i++)
    //     {
    //         while(count[i]>0)
    //         {
    //             if(ind>=n)
    //             {
    //                 ind=1;
    //             }
    //             arr[ind]='a'+i;
    //             ind+=2;
    //             count[i]--;
    //         }
    //     }
    //     string ans="";
    //     for(int i=0;i<n;i++)
    //     {
    //         ans+=arr[i];
    //     }
    //     return ans;
        

    // }
    string reorganizeString(string s) {
        map<char,int> mp;
        for(auto it:s)
        {
            mp[it]++;
        }

        priority_queue<pair<int,char>> pq;

        for(auto it:mp)
        {
            pq.push(make_pair(it.second,it.first));
        }

        string ans="";
        while(pq.size()>1)
        {
            auto top1=pq.top();
            pq.pop();

            auto top2=pq.top();
             pq.pop();

            ans+=top1.second;
            ans+=top2.second;

            top1.first=top1.first-1;
            top2.first=top2.first-1;

            if(top1.first>0)
            {
                pq.push(top1);
            }
            if(top2.first>0)
            {
                pq.push(top2);
            }
        }
        while(!pq.empty())
        {
            auto top=pq.top();
            pq.pop();
            if(top.first >1)
            {
                return "";
            }
            else{
                ans+=top.second;
                top.first=top.first-1;
            }
            
        }
        return ans;

    }
};