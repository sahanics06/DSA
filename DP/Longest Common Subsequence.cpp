/*
Given two strings s1 and s2, return the length of their longest common subsequence (LCS). If there is no common subsequence, 
return 0.

A subsequence is a sequence that can be derived from the given string by deleting some or no elements without changing 
the order of the remaining elements. For example, "ABE" is a subsequence of "ABCDE".

Examples:

Input: s1 = "ABCDGH", s2 = "AEDFHR"
Output: 3
Explanation: The longest common subsequence of "ABCDGH" and "AEDFHR" is "ADH", which has a length of 3.
Input: s1 = "ABC", s2 = "AC"
Output: 2
Explanation: The longest common subsequence of "ABC" and "AC" is "AC", which has a length of 2.
Input: s1 = "XYZW", s2 = "XYWZ"
Output: 3
Explanation: The longest common subsequences of "XYZW" and "XYWZ" are "XYZ" and "XYW", both of length 3.
Constraints:
1<= s1.size(), s2.size() <=103
Both strings s1 and s2 contain only uppercase English letters.

  */

// Solution optimised. Top down. Here dp[i][j] represent length of subsequence.
// T.C- O(N*N) two for loop
// Space- O(N*N) for dp vector

class Solution {
  public:
    int lcs(string &s1, string &s2) {
        // code here
        int n=s1.length(), m=s2.length();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
            }
        }
        return dp[n][m];
    }
};

// Solution using recursion and memoization.
// T.C- O(N*N) for iterating through two strings.
// T.C- O(N*N) for dp vector plus recursion stack

class Solution {
  public:
    int solve(string &s1, string &s2, vector<vector<int>>&dp, int i, int j)
    {
        if(i<0 || j<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int taken=0, not_taken=0;
        if(s1[i]==s2[j])
        {
            taken = 1+solve(s1, s2, dp, i-1, j-1);
        }
        not_taken = max(solve(s1,s2,dp,i-1,j), solve(s1, s2, dp, i, j-1));
        return dp[i][j] = max(taken, not_taken);
    }
    int lcs(string &s1, string &s2) {
        // code here
        int n=s1.length(), m=s2.length();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return solve(s1, s2, dp, n-1, m-1);
    }
};

// Solution using recursion. TLE. Here we use method of taken and not taken.
// T.C- 2^N
// T.C- O(N) recursion stack

class Solution {
  public:
    int solve(string &s1, string &s2, int i, int j)
    {
        if(i<0 || j<0)
            return 0;
        int taken=0, not_taken=0;
        if(s1[i]==s2[j])
        {
            taken = 1+solve(s1, s2, i-1, j-1);
        }
        not_taken = max(solve(s1,s2,i-1,j), solve(s1, s2, i, j-1));
        return max(taken, not_taken);
    }
    int lcs(string &s1, string &s2) {
        // code here
        int n=s1.length(), m=s2.length();
        return solve(s1, s2, n-1, m-1);
    }
};
