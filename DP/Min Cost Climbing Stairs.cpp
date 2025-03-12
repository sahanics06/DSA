/*
Given an array of integers cost[] where cost[i] is the cost of the ith step on a staircase. Once the cost is paid, 
you can either climb one or two steps. Return the minimum cost to reach the top of the floor.
Assume 0-based Indexing. You can either start from the step with index 0, or the step with index 1.

Examples:

Input: cost[] = [10, 15, 20]
Output: 15
Explanation: Cheapest option is to start at cost[1], pay that cost, and go to the top.


Input: cost[] = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
Output: 6
Explanation: Cheapest option is to start on cost[0], and only step on 1s, skipping cost[3].


Constraints:
2 ≤ cost.size() ≤ 105
0 ≤ cost[i] ≤ 999
  */

/*
Solution without using space.
T.C- O(N)
Space- (1)
*/

class Solution {
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int one=cost[0], two=cost[1];
        for(int i=2; i<n; i++)
        {
            int tmp=two;
            two = min(one, two)+cost[i];
            one=tmp;
        }
        return min(one, two);
    }
};

/*
Solution using 1D dp.
T.C- O(N)
Space- O(N)
*/
class Solution {
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1, 0);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2; i<n; i++)
        {
            dp[i]=min(dp[i-1], dp[i-2])+cost[i];
        }
        return min(dp[n-1], dp[n-2]);
    }
};

/*
Solution using recursion and memoization.
  We have to check from n-1 and n-2 and then return the minimum.
  T.C- O(N)
  Space- O(1)
  */

class Solution {
  public:
    int solve(vector<int>&cost, vector<int>&dp, int i)
    {
        if(i==0||i==1)
        {
            return cost[i];
        }
        if(dp[i]!=-1)
            return dp[i];
        int one=INT_MAX, two=INT_MAX;
        one = solve(cost, dp, i-1);
        two = solve(cost, dp, i-2);
        return dp[i]=cost[i]+min(one, two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        int n=cost.size();
        vector<int>dp1(n+1, -1), dp2(n+1, -1);
        return min(solve(cost, dp1, n-2),solve(cost, dp2, n-1));
    }
};
