/*Problem statement
The n-th term of Fibonacci series F(n), where F(n) is a function, is calculated using the following formula -

    F(n) = F(n - 1) + F(n - 2), 
    Where, F(1) = 1, F(2) = 1

Provided 'n' you have to find out the n-th Fibonacci Number. Handle edges cases like when 'n' = 1 or 'n' = 2 by using conditionals like if else and return what's expected.

"Indexing is start from 1"*/

//Top-Down Approach => recursion + memonization
class Solution {
public:
    int f(int n, vector<int>& dp) {
        if (n == 1 || n == 0) {
            return n;
        }

        if (dp[n] != -1) {
            return dp[n];
        }

        dp[n] = f(n - 1, dp) + f(n - 2, dp);

        return dp[n];
    }

    int fib(int n) {
        vector<int> dp(n + 1);
        for (int i=0; i <= n; i++) {
            dp[i] = -1;
        }
        int ans = f(n, dp);
        return ans;
    }
};

//Bottom-Up Approach => Tabulation
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> dp(n+1);

    dp[0] = 0;
    dp[1] = 1;

    for(int i=2; i<n+1; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout<< dp[n]<<endl;
}

//Space Optimization
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int prev2 = 0;
    int prev1 = 1;

    for(int i=2; i<n+1; i++){
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    cout<< prev1<<endl;
}
