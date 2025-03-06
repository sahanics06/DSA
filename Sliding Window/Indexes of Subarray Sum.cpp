/*
Given an array arr[] containing only non-negative integers, your task is to find a continuous subarray (a contiguous sequence of elements) whose sum equals a 
specified value target. You need to return the 1-based indices of the leftmost and rightmost elements of this subarray. You need to find the first subarray whose sum 
is equal to the target.

Note: If no such array is possible then, return [-1].

Examples:

Input: arr[] = [1, 2, 3, 7, 5], target = 12
Output: [2, 4]
Explanation: The sum of elements from 2nd to 4th position is 12.
Input: arr[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], target = 15
Output: [1, 5]
Explanation: The sum of elements from 1st to 5th position is 15.
Input: arr[] = [5, 3, 4], target = 2
Output: [-1]
Explanation: There is no subarray with sum 2.
Constraints:
1 <= arr.size()<= 106
0 <= arr[i] <= 103
0 <= target <= 109

  */

// Solution optimised- Using sliding window, keep on adding to sum if sum>target then keep on subtracting unless <=target.
// T.C- O(N)
// Space-  O(1)

class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int left=0, right=0, n=arr.size(), sum=0;
        while(right<n)
        {
            sum+=arr[right];
            if(sum==target)
            {
                return {left+1, right+1};
            }
            if(sum>target)
            {
                while(sum>=target && left<=right)
                {
                    sum-=arr[left];
                    left++;
                    if(sum==target)
                        return {left+1, right+1};
                    
                }
            }
            right++;
        }
        return {-1};
    }
};


// Solution Brute Force- Using two loop find sum of every subarray.
// T.C- O(N^2)
// Space- O(1)


class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int left=-1, right=0, n=arr.size();
        for(int i=0; i<n; i++)
        {
            int sum=0;
            for(int j=i; j<n; j++)
            {
                sum+=arr[j];
                if(sum==target)
                    return {i+1, j+1};
            }
        }
        return {-1};
    }
};
