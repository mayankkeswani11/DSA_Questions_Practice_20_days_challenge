/*Given a string s, return the longest
palindromic

substring
 in s.



Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"


Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool check(string &s, int i, int j)
    {
        while (i < j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    string longestPalindrome(string s)
    {
        int n = s.size();
        int starting_index = 0;
        int max_len = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (check(s, i, j))
                {
                    if (j - i + 1 > max_len)
                    {
                        max_len = j - i + 1;
                        starting_index = i;
                    }
                }
            }
        }
        return s.substr(starting_index, max_len);

        // this wil give TlE
        //  int n = s.size();
        //  vector<string> substring;
        //  for(int i=0; i<n; i++){
        //      string temp = "";
        //      for(int j=i; j<n; j++){
        //          temp += s[j];
        //          substring.push_back(temp);
        //      }
        //  }
        //  int max_len = 0;
        //  string finalans = substring[0];
        //  int m = substring.size();
        //  for(int i=0; i<m; i++){
        //      int s = substring[i].size();
        //      if(check(substring[i], 0, s-1)){
        //          if(s > max_len){
        //              max_len = s;
        //              finalans = substring[i];
        //          }
        //      }
        //  }
        //  return finalans;
    }
};