// #include <bits/stdc++.h>
// using namespace std;
// class Solution
// {
// private:
//     void solve_problem(string &digits, int index, string output, vector<string> &ans, string mapping[])
//     {
//         if (index >= digits.size())
//         {
//             ans.push_back(output);
//             return;
//         }
//         int number = digits[index] - '0';
//         string phone_string = mapping[number];
//         for (int i = 0; i < phone_string.size(); i++)
//         {
//             output.push_back(phone_string[i]);
//             solve_problem(digits, index + 1, output, ans, mapping);
//             output.pop_back(); // after getting one substring we have to go agin to previous step so backtracking is needed
//         }
//     }

// public:
//     vector<string> letterCombinations(string digits)
//     {
//         vector<string> ans;
//         if (digits.size() == 0)
//         {
//             return ans;
//         }
//         string output = "";
//         int index = 0;
//         string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; // stored all the string mapped with  all the digits from 0 to 9
//         solve_problem(digits, index, output, ans, mapping);
//         return ans;
//     }
// };

