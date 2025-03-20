/*
You are given a matrix grid where grid[i] is either a 0 (representing water) or 1 (representing land).

An island is defined as a group of 1's connected horizontally or vertically. You may assume all four edges of the grid are surrounded by water.

The area of an island is defined as the number of cells within the island.

Return the maximum area of an island in grid. If no island exists, return 0.

Example 1:

Input: grid = [
  [0,1,1,0,1],
  [1,0,1,0,1],
  [0,1,1,0,1],
  [0,1,0,0,1]
]

Output: 6
Explanation: 1's cannot be connected diagonally, so the maximum area of the island is 6.

Constraints:

1 <= grid.length, grid[i].length <= 50
  */

/*Solution using DFS, we traverse every node and add the return value to add every time it starts dfs from a node.
  Time- M*N since every node is visited once.
  Space- M*N recursion stack if all the nodes are 1 then we will have to visit every node.
  */

class Solution {
public:
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    int dfs(vector<vector<int>>&grid, int i, int j)
    {
        int m=grid.size(), n=grid[0].size(), ans=1;
        grid[i][j]=2;
        for(int k=0; k<4; k++)
        {
            int idx = j+dx[k];
            int idy = i+dy[k];
            if(idx>=0 && idx<n && idy>=0 && idy<m && grid[idy][idx]==1)
            {
                ans = ans+dfs(grid, idy, idx);
            }
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0, m=grid.size(), n=grid[0].size();
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==1)
                {
                    grid[i][j]=2;
                    int tmp = dfs(grid, i, j);
                    ans = max(ans, tmp);
                }
            }
        }
        return ans;
    }
};


/* Solution using bfs
  Time- M*N
  Space- M*N for queue, if all elements are 1 then all 1s will enter queue
*/

class Solution {
public:
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    int bfs(vector<vector<int>>&grid, int i, int j)
    {
        int m=grid.size(), n=grid[0].size(), ans=0;
        queue<pair<int,int>>q;
        q.push({i,j});
        grid[i][j]=2;
        while(!q.empty())
        {
            int ti = q.front().first;
            int tj = q.front().second;
            q.pop();
            
            for(int k=0; k<4; k++)
            {
                int idx = tj+dx[k];
                int idy = ti+dy[k];
                if(idx>=0 && idx<n && idy>=0 && idy<m && grid[idy][idx]==1)
                {
                    q.push({idy, idx});
                    grid[idy][idx]=2;/* here marking is important because common adjacent node can get added two times. Example for a node A its right node will add its down 
                                        and A's down node will add right node. D will be added twice if we dont mark it visited while adding in queue in first time.
                                        A  B
                                        C  D    */
                }
            }
            ans++;
        }        
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0, m=grid.size(), n=grid[0].size();
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==1)
                {
                    int tmp = bfs(grid, i, j);
                    ans = max(ans, tmp);
                }
            }
        }
        return ans;
    }
};
