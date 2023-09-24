/*Implement pow(x, n), which calculates x raised to the power n (i.e., xn).



Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25


Constraints:

-100.0 < x < 100.0
-231 <= n <= 231-1
n is an integer.
Either x is not zero or n > 0.
-104 <= xn <= 104*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    double myPow(double x, int n)
    {
        // this is first approacg which didn't pass all cases
        //  double power=1.00;

        // if(n>0)
        // {
        //     for(int i=1;i<=(long long)n;i++)
        //     {
        //         power=power*x;
        //     }
        // }
        // else{
        //     for(int i=1;i<=-n;i++)
        //     {
        //         power=power*x;
        //     }
        //     return 1/power;
        // }

        // return power;

        // this is my second approach
        // if (n == 0)
        // {
        //     return 1;
        // }
        // if (n == 1)
        // {
        //     return x;
        // }
        // if (n > 0)
        // {
        //     double ans = myPow(x, n / 2);
        //     if (n % 2 == 0)
        //     {
        //         return ans * ans;
        //     }
        //     else
        //     {
        //         return x * ans * ans;
        //     }
        // }
        // else
        // {
        //     double ans = myPow(x, -(n / 2));
        //     if (n % 2 == 0)
        //     {
        //         return (1 / (ans * ans));
        //     }
        //     else{
        //         return (1/(x*ans*ans));
        //     }
        // }

        double ans = 1;
        long long m = n;
        if (n < 0)
        {
            m = (-1) * m;
        }

        while (m > 0)
        {
            if (m % 2 == 1)
            {
                ans = ans * x;
                m = m - 1;
            }
            else
            {
                x = x * x;
                m = m / 2;
            }
        }
        if (n < 0)
        {
            return 1 / ans;
        }
        return ans;
    }
};