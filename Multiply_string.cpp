// Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

// Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

// Example 1:

// Input: num1 = "2", num2 = "3"
// Output: "6"
// Example 2:

// Input: num1 = "123", num2 = "456"
// Output: "56088"

// Constraints:

// 1 <= num1.length, num2.length <= 200
// num1 and num2 consist of digits only.
// Both num1 and num2 do not contain any leading zero, except the number 0 itself

class Solution
{
public:
    // integer overflow mardena bhai

    // string multiply(string num1, string num2) {
    //     long long number1=0;
    //     long long number2=0;

    //     for(int i=0;i<num1.size();i++)
    //     {
    //         number1=number1*10+(num1[i]-'0');
    //     }
    //     for(int i=0;i<num2.size();i++)
    //     {
    //         number2=number2*10+(num2[i]-'0');
    //     }
    //     return to_string((long long)number1*(long long)number2);
    // }

    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
        {
            return "0";
        }
        vector<int> ans(num1.size() + num2.size(), 0);
        for (int i = num1.size() - 1; i >= 0; i--)
        {
            for (int j = num2.size() - 1; j >= 0; j--)
            {
                int n1 = num1[i] - '0';
                int n2 = num2[j] - '0';
                ans[i + j + 1] += (n1 * n2);
                ans[i + j] += ans[i + j + 1] / 10;
                ans[i + j + 1] = ans[i + j + 1] % 10;
            }
        }
        string res = "";
        int i = 0;
        while (ans[i] == 0)
            i++;
        while (i < ans.size())
        {
            res += to_string(ans[i++]);
        }
        return res;
    }
};