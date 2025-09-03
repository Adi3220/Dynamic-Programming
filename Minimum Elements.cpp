/*Problem statement
You are given an array of ‘N’ distinct integers and an integer ‘X’ representing the target sum. You have to tell the minimum number of elements you have to take to reach the target sum ‘X’.

Note:
You have an infinite number of elements of each type.
For example
If N=3 and X=7 and array elements are [1,2,3]. 
Way 1 - You can take 4 elements  [2, 2, 2, 1] as 2 + 2 + 2 + 1 = 7.
Way 2 - You can take 3 elements  [3, 3, 1] as 3 + 3 + 1 = 7.
Here, you can see in Way 2 we have used 3 coins to reach the target sum of 7.
Hence the output is 3.*/

//Recursive approach
#include <bits/stdc++.h> 
int solveR(vector<int>& num, int x){
    if(x == 0)
        return 0;
    
    if(x < 0)
        return INT_MAX;

    int mini = INT_MAX;

    for(int i=0; i<num.size(); i++){
        int ans = solveR(num, x-num[i]);
        if(ans != INT_MAX)
            mini = min(mini, 1+ans);
    }

    return mini;
}

int minimumElements(vector<int> &num, int x)
{
    int ans = solveR(num, x);
    if(ans == INT_MAX)
        return -1;
    
    return ans;
}

//Top-Down Approach => recursion + memonization
#include <bits/stdc++.h> 
int solveRM(vector<int>& num, int x, vector<int>& dp){
    if(x==0)
        return 0;
    
    if(x<0)
        return INT_MAX;

    int mini = INT_MAX;

    if(dp[x] != -1)
        return dp[x];

    for(int i=0; i<num.size(); i++){
        int ans = solveR(num, x-num[i]);
        if(ans != INT_MAX)
            mini = min(mini, 1+ans);
    }

    dp[x]=mini;

    return mini; 
}

int minimumElements(vector<int> &num, int x)
{
    vector<int> dp(x+1, -1);
    int ans = solveRM(num, x, dp);

    if(ans == INT_MAX)
        return -1;

    return ans;
}

//Bottom-Up Approach => Tabulation
#include <bits/stdc++.h> 
int solveT(vector<int>& num, int x){
    vector<int> dp(x+1, INT_MAX);
    dp[0] = 0;

    for(int i=1; i<=x; i++){
        for(int j=0; j<num.size(); j++){
            if(i-num[j] >= 0 && dp[i-num[j]] != INT_MAX){
                dp[i] = min(dp[i], 1 + dp[i-num[j]]);
            }
        }
    }

    if(dp[x] == INT_MAX){
        return -1;
    }

    return dp[x];
}

int minimumElements(vector<int> &num, int x)
{
    return solveT(num, x);
}
