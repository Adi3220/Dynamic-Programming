/*Problem statement
You are given an array/list of ‘N’ integers. You are supposed to return the maximum sum of the subsequence with the constraint that no two elements are adjacent in the given array/list.

Note:
A subsequence of an array/list is obtained by deleting some number of elements (can be zero) from the array/list, leaving the remaining elements in their original order.*/

//Recursive Approach
#include <bits/stdc++.h> 
int solveR(vector<int>& nums, int n){
    if(n > nums.size()-1)
        return 0;

    int incl = solveR(nums, n+2) + nums[n];
    int excl = solveR(nums, n+1) + 0;

    return max(incl, excl);
}

int maximumNonAdjacentSum(vector<int> &nums){
    
    int n = nums.size();
    int ans = solveR(nums, 0);
    return ans;

}

//Top-down Approach = Recursion+memoization
#include <bits/stdc++.h> 

int solveRM(vector<int>& nums, int n, vector<int>& dp){
    if(n > nums.size()-1)
        return 0;

    if(dp[n] != -1)
        return dp[n];

    int incl = solveRM(nums, n+2, dp) + nums[n];
    int excl = solveRM(nums, n+1, dp) + 0;

    dp[n] = max(incl, excl);
    return dp[n];
}

int maximumNonAdjacentSum(vector<int> &nums){
    
    int n = nums.size();
    vector<int> dp(n,-1);
    int ans = solveRM(nums, 0, dp);
    return ans;

}

//Bottom-up Apprach = Tabulation
#include <bits/stdc++.h> 
int solveT(vector<int>& nums){
    int n = nums.size();
    vector<int> dp(n, 0);

    dp[0] = nums[0];

    for(int i=1; i<n; i++){
        int incl = dp[i-2] + nums[i];
        int excl = dp[i-1] + 0;
        dp[i] = max(incl, excl);
    }

    return dp[n-1];
}

int maximumNonAdjacentSum(vector<int> &nums){
    
    int ans = solveT(nums);
    return ans;

}

//Space Optimization
#include <bits/stdc++.h> 
int solveSO(vector<int>& nums){
    int n = nums.size();

    int prev2 = 0;
    int prev1 = nums[0];

    for(int i=1; i<n; i++){
        int incl = prev2 + nums[i];
        int excl = prev1 + 0;

        int curr = max(incl, excl);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int maximumNonAdjacentSum(vector<int> &nums){
    
    int ans = solveSO(nums);
    return ans;

}
