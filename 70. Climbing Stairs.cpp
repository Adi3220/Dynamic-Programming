/*You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 
Constraints:

1 <= n <= 45*/

class Solution {
public:
    
    int solve(int nStairs, int i, vector<int>& dp){
        if(i == nStairs){
            return 1;
        }
        if(i > nStairs){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        dp[i] = solve(nStairs, i+1, dp) + solve(nStairs, i+2, dp);
        return dp[i];
    }


    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, 0, dp);
    }
};
