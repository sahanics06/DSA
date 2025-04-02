/*
You are given a 0-indexed integer array nums.

Return the maximum value over all triplets of indices (i, j, k) such that i < j < k. If all such triplets have a 
negative value, return 0.

The value of a triplet of indices (i, j, k) is equal to (nums[i] - nums[j]) * nums[k].

Example 1:

Input: nums = [12,6,1,2,7]
Output: 77
Explanation: The value of the triplet (0, 2, 4) is (nums[0] - nums[2]) * nums[4] = 77.
It can be shown that there are no ordered triplets of indices with a value greater than 77. 
Example 2:

Input: nums = [1,10,3,4,19]
Output: 133
Explanation: The value of the triplet (1, 2, 4) is (nums[1] - nums[2]) * nums[4] = 133.
It can be shown that there are no ordered triplets of indices with a value greater than 133.
Example 3:

Input: nums = [1,2,3]
Output: 0
Explanation: The only ordered triplet of indices (0, 1, 2) has a negative value of (nums[0] - nums[1]) * nums[2] = -3. 
Hence, the answer would be 0.

Constraints:

3 <= nums.length <= 100
1 <= nums[i] <= 106

  */

/*
Solution using Brute Force
We use three loop for i, j, k and find the ans
    Time- O(N^3)
    Space- O(1)
*/
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        for(int i=0; i<n-2; i++)
        {
            for(int j=i+1; j<n-1; j++)
            {
                for(int k=j+1; k<n; k++)
                {
                    long long tmp = (long long)(nums[i]-nums[j])*nums[k];
                    ans = max(ans, tmp);
                }
            }
        }
        return ans;
    }
};


/*
Solution using two loop, outer loop for k and inner loop for j; We find max value of i from [0,j) and then subtract
it from nums[j].

    Time - O(N^2)
    Space - O(1)
*/

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        for(int k=2; k<n; k++)
        {
            int mx = nums[0];
            for(int j=1; j<k; j++)
            {
                mx = max(mx, nums[j-1]);
                ans = max(ans, (long long)(mx-nums[j])*nums[k]);
            }
        }
        return ans;
    }
};


/*Solution more optimised then above
  We take two vector to store maximum element till left and right side of ith index, Then we fit it into formula 
  for every ith index maximum left of it anf right of it.
      Time - O(N)
      Space - O(N) for storing left maximum and right maximum.
*/

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        vector<int>left(n,0), right(n,0);
        left[0]=nums[0];
        right[n-1]=nums[n-1];
        for(int i=1; i<n-1; i++)
        {
            left[i] = max(left[i-1], nums[i]);
            right[n-i-1] = max(right[n-i], nums[n-i-1]);
        }
        for(int i=1; i<n-1; i++)
        {
            ans = max(ans, (long long)(left[i-1]-nums[i])*right[i+1]);
        }
        return ans;
    }
};


/*
Solution more optimised then previous.
We see that answer depends on maximum of nums[i], difference of nums[i] and nums[j] and maximum of nums[k].
So we find max of nums[i] in imx, maximum of difference in dmx, and for every k we find maximum ans.

    Time - O(N)
    Space - O(1)
*/

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long dmx=0, ans=0;
        int n = nums.size(), imx=0;
        for(int k=0; k<n; k++)
        {
            ans = max(dmx*nums[k], ans);
            imx = max(imx, nums[k]);
            dmx = max(dmx, (long long)imx - nums[k]);
        }
        return ans;
    }
};
