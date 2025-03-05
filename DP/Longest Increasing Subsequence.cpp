/*
Given an array arr[] of non-negative integers, the task is to find the length of the Longest Strictly Increasing Subsequence (LIS).

A subsequence is strictly increasing if each element in the subsequence is strictly less than the next element.

Examples:

Input: arr[] = [5, 8, 3, 7, 9, 1]
Output: 3
Explanation: The longest strictly increasing subsequence could be [5, 7, 9], which has a length of 3.
Input: arr[] = [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15]
Output: 6
Explanation: One of the possible longest strictly increasing subsequences is [0, 2, 6, 9, 13, 15], which has a length of 6.
Input: arr[] = [3, 10, 2, 1, 20]
Output: 3
Explanation: The longest strictly increasing subsequence could be [3, 10, 20], which has a length of 3.
Constraints:
1 ≤ arr.size() ≤ 103
0 ≤ arr[i] ≤ 106

  */

/* Solution using recursion and memoization. Here we used pre=-1 as initial value and check dp[i][pre+1], pre+1 so that we dont go undefine index.
  T.C- N*N for using 2d Dp
  Space- N*N
*/

class Solution {
  public:
    int solve(vector<int>&arr, vector<vector<int>>&dp, int i, int pre)
    {
        if(i<0)
        {
            return 0;
        }
        int taken=0, not_taken=0;
        if(dp[i][pre+1]!=-1)
        {
            return dp[i][pre+1];
        }
        if(pre==-1 || arr[pre]>arr[i])
        {
            taken = 1+solve(arr, dp, i-1, i);
        }
        not_taken = solve(arr, dp, i-1, pre);
        return dp[i][pre+1] = max(taken, not_taken);
    }
    int lis(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        return solve(arr, dp, n-1, -1);
    }
};
