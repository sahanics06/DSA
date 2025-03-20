/*
Given a 2D grid grid where '1' represents land and '0' represents water, count and return the number of islands.

An island is formed by connecting adjacent lands horizontally or vertically and is surrounded by water. You may assume water is surrounding the grid 
(i.e., all the edges are water).

Example 1:

Input: grid = [
    ["0","1","1","1","0"],
    ["0","1","0","1","0"],
    ["1","1","0","0","0"],
    ["0","0","0","0","0"]
  ]
Output: 1
Example 2:

Input: grid = [
    ["1","1","0","0","1"],
    ["1","1","0","0","1"],
    ["0","0","1","0","0"],
    ["0","0","0","1","1"]
  ]
Output: 4
Constraints:

1 <= grid.length, grid[i].length <= 100
grid[i][j] is '0' or '1'.

  */

/* Solution using BFS. We traverse grid and if grid[i][j]=='1' then we call checkIsland and mark all adjacent '1's to '2'.
  Time- M*N since we visit every node only once and other time we just check if its value is 1,0 or 2
  Space- BFS queue M*N if all are island i.e '1' then every entry will enter in query and M*N if we use visited array.
  */

class Solution {
public:
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    void checkIsland(vector<vector<char>>&grid, int i, int j)
    {
        queue<pair<int,int>>q;
        int m=grid.size(), n=grid[0].size();
        q.push({i,j});
        while(!q.empty())
        {
            int ti=q.front().first;
            int tj=q.front().second;
            q.pop();
            grid[ti][tj]='2';
            for(int k=0; k<4; k++)
            {
                int idx = tj+dx[k];
                int idy = ti+dy[k];
                if(idx>=0 && idx<n && idy>=0 && idy<m && grid[idy][idx]=='1')
                {
                    grid[idy][idx]='2';
                    q.push({idy, idx});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0, m=grid.size(), n=grid[0].size();
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]=='1')
                {
                    grid[i][j]='2';
                    checkIsland(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};

/*
Solution using DFS
  Time- M*N since we visit every node only once and other time we just check if its value is 1,0 or 2
  Space- recursion stack M*N if all are '1's then dfs will be called for every cell.
*/

class Solution {
public:
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    void dfs(vector<vector<char>>&grid, int i, int j)
    {
        int m=grid.size(), n=grid[0].size();
        grid[i][j]='2';
        for(int k=0; k<4; k++)
        {
            int idx = j+dx[k];
            int idy = i+dy[k];
            if(idx>=0 && idx<n && idy>=0 && idy<m && grid[idy][idx]=='1')
            {
                dfs(grid, idy, idx);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0, m=grid.size(), n=grid[0].size();
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]=='1')
                {
                    grid[i][j]='2';
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};

