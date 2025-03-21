/*
You are given a m × n m×n 2D grid initialized with these three possible values:
-1 - A water cell that can not be traversed.
0 - A treasure chest.
INF - A land cell that can be traversed. We use the integer 2^31 - 1 = 2147483647 to represent INF.
Fill each land cell with the distance to its nearest treasure chest. If a land cell cannot reach a treasure chest than the value should remain INF.

Assume the grid can only be traversed up, down, left, or right.

Modify the grid in-place.

Example 1:

Input: [
  [2147483647,-1,0,2147483647],
  [2147483647,2147483647,2147483647,-1],
  [2147483647,-1,2147483647,-1],
  [0,-1,2147483647,2147483647]
]

Output: [
  [3,-1,0,1],
  [2,2,1,-1],
  [1,-1,2,-1],
  [0,-1,3,4]
]
Example 2:

Input: [
  [0,-1],
  [2147483647,2147483647]
]

Output: [
  [0,-1],
  [1,2]
]
Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 100
grid[i][j] is one of {-1, 0, 2147483647}
  */


/*Solution using BFS. First we have inserted values with 0 in queue, then we iterate over queue and update distance in grid, if for new entry the distance present in grid is less then we add that in queue and also update grid value.
  Time- M*N we traverse only one time in grid
  Space- M*N if all values are part of answer then we push that in queue.
*/

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size(), mx=2e31-1;
        queue<pair<int,pair<int,int>>>q;
        int dj[4]={0,1,0,-1};
        int di[4]={1,0,-1,0};
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==0)
                {
                    q.push({0, {i,j}});
                }
            }
        }
        while(!q.empty())
        {
            int d=q.front().first;
            int i=q.front().second.first;
            int j=q.front().second.second;
            q.pop();
            for(int k=0; k<4; k++)
            {
                int ti = di[k]+i;
                int tj = dj[k]+j;
                if(ti>=0 && ti<m && tj>=0 && tj<n)
                {
                    if(grid[ti][tj]==mx) //traversable point
                    {
                        grid[ti][tj]=d+1;
                        q.push({d+1, {ti,tj}});
                    }
                    else if(grid[ti][tj]>0 && grid[ti][tj]>d+1) // if new value has less distance then we update value and add in queue
                    {
                        grid[ti][tj]=d+1;
                        q.push({d+1, {ti,tj}});
                    }
                }
            }
        }
    }
};


// Solution using DFS, if conditions satifies then dfs is called with d+1
// Time - M*N for every possible nodes
// Space- M*N recursion stack space
class Solution {
public:
    int dj[4]={0,1,0,-1};
    int di[4]={1,0,-1,0};
    double mx=2e31-1;
    void dfs(vector<vector<int>>& grid, int d, int i, int j, int m, int n)
    {
        for(int k=0; k<4; k++)
        {
            int ti = di[k]+i;
            int tj = dj[k]+j;
            if(ti>=0 && ti<m && tj>=0 && tj<n && (grid[ti][tj]==mx || grid[ti][tj]>d+1))
            {
                grid[ti][tj]=d+1;
                dfs(grid, d+1, ti, tj, m, n);
            }
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size(), mx=2e31-1;        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==0)
                {
                    dfs(grid, 0, i, j, m, n);
                }
            }
        }
    }
};

