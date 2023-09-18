/*Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //brute force solution of this problem 

        //step1--> check the string size if it is 1 than longest prefix is that string only
        if(strs.size()==1)
        {
            return strs[0];
        }
        ///step 2--> store the first string from string array
        
        string first=strs[0];

        //step3--> initialize count variable with count=0 and it is used to keep track of the common prefix 
        int count=0;
        // step 4--> comapre with the another strings in the array and update count according to that

        int mini=INT_MAX;
        for(int i=1;i<strs.size();i++)
        {
           for(int j=0;j<first.size()&&j<strs[i].size();j++)
            {
                if(first[j]==strs[i][j])
                {
                    count++;
                }
                else{
                    break;
                }
                
            }
            mini=min(mini,count);
            if(mini==0)
            {
                return "";
            }
            count=0;
        }

        //step5-->check now that if mini is 0 then return empty string or greater than zero then return first mini number of characters from first string and append it to ans  and return it
        string ans="";
        if(mini==0)
        {
            ans="";
        }
        else{
            for(int i=0;i<mini;i++)
            {
                ans+=first[i];
            }
        }
        return ans;





        //better solution for this problem


        // sort(strs.begin(),strs.end());
        // int a=strs.size();
        // string n=strs[0],m=strs[a-1],ans="";
        // for(int i=0;i<n.size();i++){
        //     if(n[i]==m[i]){ans+=n[i];}
        //     else break;
        // }
        // return ans;


    }
};

//write main code by your own