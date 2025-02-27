/*
A sequence x1, x2, ..., xn is Fibonacci-like if:

n >= 3
xi + xi+1 == xi+2 for all i + 2 <= n
Given a strictly increasing array arr of positive integers forming a sequence, return the length of the longest 
Fibonacci-like subsequence of arr. If one does not exist, return 0.

A subsequence is derived from another sequence arr by deleting any number of elements (including none) from arr, 
without changing the order of the remaining elements. For example, [3, 5, 8] is a subsequence of [3, 4, 5, 6, 7, 8].

Example 1:

Input: arr = [1,2,3,4,5,6,7,8]
Output: 5
Explanation: The longest subsequence that is fibonacci-like: [1,2,3,5,8].
Example 2:

Input: arr = [1,3,7,11,12,14,18]
Output: 3
Explanation: The longest subsequence that is fibonacci-like: [1,11,12], [3,11,14] or [7,11,18].

Constraints:

3 <= arr.length <= 1000
1 <= arr[i] < arr[i + 1] <= 109

  */

// Solution using for loop
// We iterate the array and find a+b ==c in array using binary search. We keep on upadting index for the next element.
// T.C- O(log(N)*N^2)
// Space- O(1)

class Solution {
public:
    int bs(vector<int>&arr, long long num, int l)
    {
        int r=arr.size()-1;
        while(l<=r)
        {
            int m = l+(r-l)/2;
            if(arr[m]==num)
                return m;
            if(arr[m]<num)
            {
                l=m+1;
            }
            else
            {
                r=m-1;
            }
        }
        return -1;
    }
    int lenLongestFibSubseq(vector<int>& arr) {
        int ans=0;
        int tmp, n=arr.size();
        for(int i=0; i<n; i++)
        {
            tmp=2;
            int idx, a, b;
            long long sum;
            for(int j=i+1; j<n; j++)
            {
                idx=j+1;
                a=i;
                b=j;
                while(1)
                {
                    //cout<<i<<"  "<<j<<endl;
                    sum = arr[a]+arr[b];
                    int index = bs(arr, sum, idx);
                    //cout<<a<<"  "<<b<<"  "<<index<<endl;
                    if(index<0)
                        break;
                    idx = index;
                    a=b;
                    b=index;
                    tmp++;
                }
                if(tmp>2)
                {
                    ans=max(ans, tmp);
                }
                tmp=2;
            }
        }
        return ans;
    }
};

// Solution using recursion; here we used to loop for two numbers to start with then we keep on finding the next
// number using recursion
// T.C- O(N^3) two for loop and N for recursion on each element.
// Space- O(N) for recursion stack
class Solution {
public:
    int solve(vector<int>&arr, unordered_map<int,int>&mp, int a, int b)
    {
        if(mp.count(arr[b]-arr[a]) && mp[arr[b]-arr[a]]<a)
        {
            return solve(arr, mp, mp[arr[b]-arr[a]], a)+1;
        }
        return 2; // 2 for if we dont find next element then still we have a and b as fibonacci series.
    }
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size(), ans=0;
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++)
        {
            mp[arr[i]]=i;
        }
        for(int j=1; j<n; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                int tmp = solve(arr, mp, j, k);
                if(tmp>2)
                    ans = max(ans, tmp);
            }
        }
        return ans;
    }
};

// Above recursion using memoization

class Solution {
public:
    int solve(vector<int>&arr, unordered_map<int,int>&mp, int a, int b, vector<vector<int>>&dp)
    {
        if(dp[a][b]!=-1)
            return dp[a][b];
        int target = arr[b]-arr[a];
        if(mp.count(target) && mp[target]<a)
        {
            return dp[a][b] = solve(arr, mp, mp[target], a, dp)+1;
        }
        return dp[a][b] = 2;
    }
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size(), ans=0;
        vector<vector<int>>dp(n, vector<int>(n,-1));
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++)
        {
            mp[arr[i]]=i;
        }
        for(int j=1; j<n; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                int tmp = solve(arr, mp, j, k, dp);
                if(tmp>2)
                    ans = max(ans, tmp);
            }
        }
        return ans;
    }
};


// Optimised solution . Bottom up. We have used the recursion in the above solution to deduce the steps in bottom up
// T.C- O(N)
// Space- O(N*N) for table

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size(), ans=0;
        vector<vector<int>>dp(n, vector<int>(n,2)); // we have initailised every number to 2 because we have to 
      //find maximum lenth forming fibonaci with i,j; so atleast 2 elements are always there.
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++)
        {
            mp[arr[i]]=i;
        }
        for(int j=1; j<n; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                int target = arr[k]-arr[j];
                if(mp.count(target) && mp[target]<j)
                {
                    int i=mp[target];
                    dp[j][k] = dp[i][j]+1;
                }
                ans = max(ans, dp[j][k]);
            }
        }
        return ans>2?ans:0;
    }
};
