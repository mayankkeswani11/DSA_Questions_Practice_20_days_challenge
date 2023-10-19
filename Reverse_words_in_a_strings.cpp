Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

 

Example 1:

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Example 2:

Input: s = "God Ding"
Output: "doG gniD"
 

Constraints:

1 <= s.length <= 5 * 104
s contains printable ASCII characters.
s does not contain any leading or trailing spaces.
There is at least one word in s.
All the words in s are separated by a single space.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        string temp="";
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]!=' ')
            {
                temp=temp+s[i];
            }
            else{
                if(ans=="")
                {
                    ans=temp;
                }
                else{
                    ans=temp+' '+ans;
                }
                temp="";
            }
        }
        if(ans!="")
        {
            ans=temp+' '+ans;
        }
        else{
            ans=temp;
        }
        return ans;
    }
};