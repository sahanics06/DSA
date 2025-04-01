/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. 
If this is impossible, return -1.

Example 1:

Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 
4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 
Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.

  */

/*
Solution using BFS . We first insert all the coordinates for rotten oranges. Then we use BFS on the size of queue.
For a particular size of queue we have all the coordinates that will take same time so we have taken the concept 
of iterating over the size of queue and insert all the adjacent valid points. By doing this we have covered all 
the adjacent coordinates at minimum time.

Time- O(M*N)- For every point we only traverse once.
Space- Queue- O(N)- If all the points are rotten.
*/

class Solution {
public:
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    int bfs(vector<vector<int>>& grid, queue<pair<int,int>>&q)
    {
        int m=grid.size(), n=grid[0].size(), ans=0;
        //queue<pair<int,int>>q;
        //q.push({i,j});
        while(!q.empty())
        {
            int qs=q.size();
            ans++;
            int tmp=ans+2;
            while(qs)
            {
                int x=q.front().second;
                int y=q.front().first;
                qs--;
                q.pop();
                grid[y][x]=-1;
                for(int k=0; k<4; k++)
                {
                    int tx=dx[k]+x;
                    int ty=dy[k]+y;
                    if(tx>=0 && tx<n && ty>=0 && ty<m && grid[ty][tx]==1)
                    {
                        q.push({ty,tx});
                        grid[ty][tx]=-1;
                    }
                }
            }            
        }
        return ans-1;
    }
        
    int orangesRotting(vector<vector<int>>& grid) {
        int ans=0;
        queue<pair<int,int>>q;
        int m=grid.size(), n=grid[0].size();
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                    //int tmp = bfs(grid, i, j);
                    //cout<<"hello"<<endl;
                    //ans = max(ans, tmp);
                }
            }
        }
        if(q.size())
            ans = bfs(grid, q);
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
                //ans = max(ans, grid[i][j]);
                //cout<<grid[i][j]<<"  ";
            }
            //cout<<endl;
        }
        return ans==0?0:ans;
    }
};


/* Solution using DFS, we call dfs passing coordinates and distance. We created vis[][] to store the distance, 
initial value is INT_MAXif for new dfs call if vis[i][j]>d then we call dfs and update distance in vis.
*/

//* Time- O(M*N) to traverse all the points, If updation is required then also for visted point we go at max(M,N)/2
distance from rooten point.
Spcae- O(M*N) vis and recursion stack (M+N) if we traverse row and column, otherwise for a point 4 point originates 
  and after one is  completed then second direction starts so it is not multiplication.
  */

  class Solution {
public:
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int y, int x, int d)
    {
        int m=grid.size(), n=grid[0].size();
        vis[y][x]=d;
        for(int k=0; k<4; k++)
        {
            int tx=dx[k]+x;
            int ty=dy[k]+y;
            if(tx>=0 && tx<n && ty>=0 && ty<m && grid[ty][tx]==1 && vis[ty][tx]>d)
            {
                dfs(grid, vis, ty, tx, d+1);
            }           
        }
    }
        
    int orangesRotting(vector<vector<int>>& grid) {
        int ans=0;
        queue<pair<int,int>>q;
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>>vis(m, vector<int>(n,INT_MAX));
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==2)
                {
                    dfs(grid, vis, i, j, 0);
                    //int tmp = bfs(grid, i, j);
                    //cout<<"hello"<<endl;
                    //ans = max(ans, tmp);
                }
            }
        }
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==1 && vis[i][j]==INT_MAX)
                {
                    return -1;
                }
                if(vis[i][j]!=INT_MAX)
                    ans = max(ans, vis[i][j]);
                cout<<grid[i][j]<<"  ";
            }
            cout<<endl;
        }
        return ans==0?0:ans;
    }
};


