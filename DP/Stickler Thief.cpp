/*
Stickler the thief wants to loot money from the houses arranged in a line. He cannot loot two consecutive houses and aims to 
maximize his total loot.
Given an array, arr[] where arr[i] represents the amount of money in the i-th house.
Determine the maximum amount he can loot.

Examples:

Input: arr[] = [6, 5, 5, 7, 4]
Output: 15
Explanation: Maximum amount he can get by looting 1st, 3rd and 5th house. Which is 6 + 5 + 4 = 15.
Input: arr[] = [1, 5, 3]
Output: 5
Explanation: Loot only 2nd house and get maximum amount of 5.
Input: arr[] = [4, 4, 4, 4]
Output: 8
Explanation: The optimal choice is to loot every alternate house. Looting the 1st and 3rd houses, or the 2nd and 4th, 
both give a maximum total of 4 + 4 = 8.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 104
  */

/* Solution using recursion and memoization
  Time- M because we traverse one index only one time.
  Space- O(M) r
*/

class Solution {
  public:
    int solve(vector<int>&arr, vector<int>&dp, int i)
    {
        if(i<0)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int taken=0, not_taken=0;
        taken = arr[i]+solve(arr, dp, i-2);
        not_taken = solve(arr, dp, i-1);
        return dp[i] = max(taken, not_taken);
    }
    int findMaxSum(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>dp(n+1, -1);
        return solve(arr, dp, n-1);
    }
};

// Solution using top down tabular way
// Time- O(N)
// Space- O(N)
class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        int n=arr.size();
        vector<int>dp(n+1, 0);
        dp[1]=max(arr[0], arr[1]);  // when in index 1 we have two choices so we take maximum from both
        dp[0]=arr[0];
        for(int i=2; i<n; i++)
        {
            dp[i] = max(dp[i-2]+arr[i], dp[i-1]);
        }
        return dp[n-1];
    }
};
