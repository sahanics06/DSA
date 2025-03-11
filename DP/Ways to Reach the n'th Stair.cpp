/*
There are n stairs, a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at 
a time. Your task is to count the number of ways, the person can reach the top (order does matter).

Examples:

Input: n = 1
Output: 1
Explanation: There is only one way to climb 1 stair. 
Input: n = 2
Output: 2
Explanation: There are 2 ways to reach 2th stair: {1, 1} and {2}.  
Input: n = 4
Output: 5
Explanation: There are five ways to reach 4th stair: {1, 1, 1, 1}, {1, 1, 2}, {2, 1, 1}, {1, 2, 1} and {2, 2}.
Constraints:
1 ≤ n ≤ 44
  */

/* Solution using 1D Dp. we see here we have two ways to go forward, taing 1 step or 2 step. So the future step ways
is sum of i-1 and i-2.
T.C- O(N)
Space- O(N)
  */

class Solution {
  public:
    int countWays(int n) {
        // your code here
        vector<int>dp(n,0);
        dp[0]=1;dp[1]=2;
        for(int i=2; i<n; i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n-1];
    }
};

// Solution using recursion and memoization.
// T.C- O(N)
// Space- O(N) -memoization vector

class Solution {
  public:
    int solve(int i, vector<int>&dp)
    {
        if(i<=0)
        {
            if(i==0)
            {
                return 1;
            }
            return 0;
        }
        return dp[i] = solve(i-1, dp)+solve(i-2, dp);
    }
    int countWays(int n) {
        // your code here
        vector<int>dp(n+1,-1);
        return solve(n, dp);
    }
};

// Solution using recursion. Take solve(i)=solve(i-1)+solve(i-2)
// T.C- 2^N
// Space- O(N) -recursion stack
class Solution {
  public:
    int solve(int i)
    {
        if(i<=0)
        {
            if(i==0)
            {
                return 1;
            }
            return 0;
        }
        return solve(i-1)+solve(i-2);
    }
    int countWays(int n) {
        // your code here
        return solve(n);
    }
};
