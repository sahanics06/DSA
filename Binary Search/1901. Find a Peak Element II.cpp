/*
A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.

Example 1:

Input: mat = [[1,4],[3,2]]
Output: [0,1]
Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.
Example 2:

Input: mat = [[10,20,15],[21,30,14],[7,16,32]]
Output: [1,1]
Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable answers.
 
Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 500
1 <= mat[i][j] <= 105
No two adjacent cells are equal.

  */

/*
  Solution using Binary Search
  We use Binary Search in columns, and then fing peak element in the column. We can also do this in row. For mid in column we find peak in that column, then we 
  see if its left and right elements are samller or not. If left is greater then this is obvious that left column will have greater elements than peak. 
  Same for right.

  Time- O(N logM) or MlogN; to find peak for every binary search O(N) and Binary Search logN
  Space- M/2 r

*/

class Solution {
public:
    int peak(vector<vector<int>>&mat, int j)
    {
        int mx=-1, idx=0;
        for(int k=0; k<mat.size(); k++)
        {
            if(mat[k][j]>mat[idx][j])
            {
                idx=k;
            }
        }
        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        int l=0, r=n-1;
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            int idx = peak(mat, mid);
            int left = mid-1>=0?mat[idx][mid-1]:-1;
            int right = mid+1<n?mat[idx][mid+1]:-1;
            if(left<mat[idx][mid] && right<mat[idx][mid])
                return {idx, mid};
            if(left>mat[idx][mid])
                r = mid-1;
            else
                l = mid+1;
        }
        return {0,0};
    }
};


/*

Brute Force 
1) We traverse every point and check if it is greater than all four elements in four directions.
    Time - M*N*4; SInce we check all 4 ditrections

2) We traverse every point and find the largest element in 2D matrix.
    Time - M*N

  */
