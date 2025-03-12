/*
Given an array nums sorted in non-decreasing order, return the maximum between the number of positive integers and the number of negative integers.

In other words, if the number of positive integers in nums is pos and the number of negative integers is neg, then return the maximum of pos and neg.
Note that 0 is neither positive nor negative. 

Example 1:

Input: nums = [-2,-1,-1,1,2,3]
Output: 3
Explanation: There are 3 positive integers and 3 negative integers. The maximum count among them is 3.
Example 2:

Input: nums = [-3,-2,-1,0,0,1,2]
Output: 3
Explanation: There are 2 positive integers and 3 negative integers. The maximum count among them is 3.
Example 3:

Input: nums = [5,20,66,1314]
Output: 4
Explanation: There are 4 positive integers and 0 negative integers. The maximum count among them is 4. 

Constraints:

1 <= nums.length <= 2000
-2000 <= nums[i] <= 2000
nums is sorted in a non-decreasing order.
  */

/* Solution using Binary Search. We find indices of first positive number and last negative number.
T.C- O(logN)
Space- O(1)
  */

class Solution {
public:
    void solve(vector<int>&nums, int &left, int &right)
    {
        int l=0, r=nums.size()-1;
        while(l<=r)   // to find last negative number
        {
            int m=l+(r-l)/2;
            if(nums[m]<0)
            {
                left=m;
                l=m+1;
            }
            else
            {
                r=m-1;
            }
        }
        l=0; r=nums.size()-1;
        while(l<=r)    // to find first positive number
        {
            int m=l+(r-l)/2;
            if(nums[m]>0)
            {
                right=m;
                r=m-1;
            }
            else
            {
                l=m+1;
            }
        }
        return;
    }
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        int left=-1, right=n;
        solve(nums, left, right);
        return max(left-0+1, n-right);
    }
};
