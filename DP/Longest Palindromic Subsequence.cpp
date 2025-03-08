/*
Given a string s, return the length of the longest palindromic subsequence.

A subsequence is a sequence that can be derived from the given sequence by deleting some or no elements without changing 
the order of the remaining elements.

A palindromic sequence is a sequence that reads the same forward and backward.

Examples:

Input: s = "bbabcbcab"
Output: 7
Explanation: Subsequence "babcbab" is the longest subsequence which is also a palindrome.
Input: s = "abcd"
Output: 1
Explanation: "a", "b", "c" and "d" are palindromic and all have a length 1.
Input: s = "agbdba"
Output: 5
Explanation: The longest palindromic subsequence is "abdba", which has a length of 5. The characters in this 
subsequence are taken from the original string "agbdba", and they maintain the order of the string while forming a 
palindrome.
Constraints:
1 ≤ s.size() ≤ 1000
The string contains only lowercase letters.

  */

/*  Solution using recursion and memoization.
  T.C- O(N*N) traversing a string both side.
  Space-  O(N*N) dp size.
*/

class Solution {
  public:
    int solve(string &s, vector<vector<int>>&dp, int i, int j)
    {
        if(i>=s.length()||j<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int taken=0, not_taken=0;
        if(s[i]==s[j])
        {
            taken = 1+solve(s, dp, i+1, j-1);
        }
        not_taken = max(solve(s, dp, i+1, j), solve(s, dp, i, j-1));
        return dp[i][j] = max(taken, not_taken);
    }
    int longestPalinSubseq(string &s) {
        // code here
        int n=s.length();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return solve(s, dp, 0, n-1);
    }
};


// Solution using two string and finding LCS between them.

class Solution {
  public:
    int solve(string &s, string &t, vector<vector<int>>&dp, int i, int j)
    {
        if(i<0||j<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int taken=0, not_taken=0;
        if(s[i]==t[j])
        {
            taken = 1+solve(s, t, dp, i-1, j-1);
        }
        not_taken = max(solve(s, t, dp, i-1, j), solve(s, t, dp, i, j-1));
        return dp[i][j] = max(taken, not_taken);
    }
    int longestPalinSubseq(string &s) {
        // code here
        int n=s.length();
        string t = s;
        reverse(t.begin(), t.end());
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return solve(s, t, dp, n-1, n-1);
    }
};



/* Solution using recursion, using taken and not_taken. for palindromic subsequence we have travarsed from front and from
back or else we could have reversed the string and find the longest common subsequence.
  T.C- 2^N
  Space- O(N) recursion staack.
*/

class Solution {
  public:
    int solve(string &s, int i, int j)
    {
        if(i>=s.length()||j<0)
            return 0;
        int taken=0, not_taken=0;
        if(s[i]==s[j])
        {
            taken = 1+solve(s, i+1, j-1);
        }
        not_taken = max(solve(s, i+1, j), solve(s, i, j-1));
        return max(taken, not_taken);
    }
    int longestPalinSubseq(string &s) {
        // code here
        return solve(s, 0, s.length()-1);
    }
};
