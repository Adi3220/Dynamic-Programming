/*Problem statement
Mr. X is a professional robber planning to rob houses along a street. Each house has a certain amount of money hidden.

All houses along this street are arranged in a circle. That means the first house is the neighbour of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses are broken into on the same night.

You are given an array/list of non-negative integers 'ARR' representing the amount of money of each house. Your task is to return the maximum amount of money Mr. X can rob tonight without alerting the police.

Note:
It is possible for Mr. X to rob the same amount of money by looting two different sets of houses. Just print the maximum possible robbed amount, irrespective of sets of houses robbed.


For example:
(i) Given the input array arr[] = {2, 3, 2} the output will be 3 because Mr X cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses. So, he’ll rob only house 2 (money = 3)

(ii) Given the input array arr[] = {1, 2, 3, 1} the output will be 4 because Mr X rob house 1 (money = 1) and then rob house 3 (money = 3).

(iii) Given the input array arr[] = {0} the output will be 0 because Mr. X has got nothing to rob.

This Problem is same as  Maximum sum of non-adjacent elements but with the twist of house in circle(Circular array)

*/

#include <bits/stdc++.h> 
long long int solve(vector<int>& nums){
    int n = nums.size();

    long long int prev2 = 0;
    long long int prev1 = nums[0];

    for(int i=1; i<n; i++){
        long long int incl = prev2 + nums[i];
        long long int excl = prev1 + 0;

        long long int curr = max(incl, excl);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    int n=valueInHouse.size();

    if(n==1){
        return valueInHouse[0];
    }

    vector<int> first, second;
    for(int i=0; i<n; i++){
        if(i != n-1)
            first.push_back(valueInHouse[i]);
        if(i != 0)
            second.push_back(valueInHouse[i]);
    }

    return max(solve(first), solve(second));
}
