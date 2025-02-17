/*
Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length such that B[i] == A[(i+x) % A.length] for every valid index i.

Example 1:

Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 3 positions to begin on the element of value 3: [3,4,5,1,2].
Example 2:

Input: nums = [2,1,3,4]
Output: false
Explanation: There is no sorted array once rotated that can make nums.
Example 3:

Input: nums = [1,2,3]
Output: true
Explanation: [1,2,3] is the original sorted array.
You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.
 
Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100

  */


// Brute Force
// T.C- O(N2)    // Space- O(N) every timewe are creating an array.

// We keep on creating a array by rotating every elements for n number of time and then check if the array is sorted or not. If sorted then return true else false at the end.

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        vector<int>tmp(n,0);
        for(int pos=0; pos<n; pos++)
        {
            for(int i=0; i<n; i++)
            {
                tmp[i] = nums[(i+pos)%n];
            }
            int c=0;
            for(int i=0; i<n-1; i++)
            {
                if(tmp[i]>tmp[i+1])
                {
                    break;
                }
                c++;
            }
            if(c==n-1)
                return true;
        }
        return false;
    }
};


// First optimised solution
// T.C- O(N)    Space- O(1)

/* Point to look at that there will always be a point in between where the arr[i-1]>arr[i]<=arr[i+1] if rotated. If we find more than 1 inversion then 
the rotated array is not sorted. Here we iterate and if previous is greater than next, means break. We found the point where rotation started. 
From this point we check if the array is sorted, if not return false
  */

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        if(nums[0]>=nums[n-1])
        {
            while(i<n-1)
            {
                if(nums[i+1]>=nums[i])
                {
                    i++;
                }
                else
                {
                    break;
                }
            }
            i++;
        }
        while(i<n-1)
        {
            if(nums[i+1]>=nums[i])
            {
                i++;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

/* Point to look at that there will always be a point in between where the arr[i-1]>arr[i]<=arr[i+1] if rotated. If we find more than 1 inversion then 
the rotated array is not sorted. We count inversion. if nums[i]>nums[i+1] then inversion count++. if count<=1 return true else false.
  */

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count=0;
        for(int i=0; i<n; i++)
        {
            count += nums[i]>nums[(i+1)%n];
        }
        return count<=1;
    }
};
