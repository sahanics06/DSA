/*
Given an array arr[], determine if it can be partitioned into two subsets such that the sum of elements in both parts is the same.

Note: Each element must be in exactly one subset.

Examples:

Input: arr = [1, 5, 11, 5]
Output: true
Explanation: The two parts are [1, 5, 5] and [11].
Input: arr = [1, 3, 5]
Output: false
Explanation: This array can never be partitioned into two such parts.
Constraints:
1 ≤ arr.size ≤ 100
1 ≤ arr[i] ≤ 200
  */

/*
Solution using top down tabulation
  T.C- N*Sum
  Space- N*Sum
*/

class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        // code here
        int n=arr.size(), sum=0;
        
        for(int i=0; i<n; i++)
        {
            sum+=arr[i];
        }
        
        vector<vector<bool>>dp(n+1, vector<bool>(sum/2+1, false));
        if(sum%2)
            return false;
            
        for(int i=0; i<n; i++) // if sum==0 then we have true for all i
        {
            dp[i][0]=true;
        }
        dp[0][arr[0]]=true; // when i==0 if arr[0]==target then it is true
        for(int i=1; i<n; i++)
        {
            for(int target=1; target<=sum/2+1; target++)
            {
                bool taken=false;
                if(target>=arr[i])
                    taken = dp[i-1][target-arr[i]];
                bool not_taken = dp[i-1][target];
                
                dp[i][target] = taken||not_taken;
            }
        }
        return dp[n-1][sum/2];
    }
};

/*
Solution using recursion and memoization.
  T.C- N*Sum
  Space- N*Sum + O(N) Auxillary space
  */

class Solution {
  public:
    bool solve(vector<int>&arr, vector<vector<int>>&dp, int i, int sum)
    {
        if(sum==0)
        {
            return true;
        }
        if(i<0)
            return false;
        if(dp[i][sum]!=-1)
        {
            return dp[i][sum];
        }
        bool taken=false;
        if(sum>=arr[i])
            taken = solve(arr, dp, i-1, sum-arr[i]);
        bool not_taken = solve(arr, dp, i-1, sum);
        
        return dp[i][sum] = taken||not_taken;
    }
    bool equalPartition(vector<int>& arr) {
        // code here
        int n=arr.size(), sum=0;
        
        for(int i=0; i<n; i++)
        {
            sum+=arr[i];
        }
        
        vector<vector<int>>dp(n+1, vector<int>(sum/2+1, -1));
        if(sum%2)
            return false;
        return solve(arr, dp, n-1, sum/2);
    }
};
