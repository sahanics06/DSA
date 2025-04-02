/*
There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. 
The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and 
bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where 
heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, 
and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from 
any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from 
cell (ri, ci) to both the Pacific and Atlantic oceans. 

Example 1:

Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
Explanation: The following cells can flow to the Pacific and Atlantic oceans, as shown below:
[0,4]: [0,4] -> Pacific Ocean 
       [0,4] -> Atlantic Ocean
[1,3]: [1,3] -> [0,3] -> Pacific Ocean 
       [1,3] -> [1,4] -> Atlantic Ocean
[1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean 
       [1,4] -> Atlantic Ocean
[2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean 
       [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
[3,0]: [3,0] -> Pacific Ocean 
       [3,0] -> [4,0] -> Atlantic Ocean
[3,1]: [3,1] -> [3,0] -> Pacific Ocean 
       [3,1] -> [4,1] -> Atlantic Ocean
[4,0]: [4,0] -> Pacific Ocean 
       [4,0] -> Atlantic Ocean
Note that there are other possible paths for these cells to flow to the Pacific and Atlantic oceans.
Example 2:

Input: heights = [[1]]
Output: [[0,0]]
Explanation: The water can flow from the only cell to the Pacific and Atlantic oceans.
 
Constraints:

m == heights.length
n == heights[r].length
1 <= m, n <= 200
0 <= heights[r][c] <= 105

  */


/*
Solution using BFS, here we insert edge points of matrix touching pacific and atlantic in two different queues.
  Then we apply bfs on queue until its empty, if the adjacent point heights[ty][tx]>=heights[y][x] then we update 
pac[ty][tx]=1; Similarly for atlantic. If for i,j  pac[i][j]==1 and at[i][j]==1 then it is valid answer.

  Time- O(M*N) if all points are valid for any ocean.
  Space- O(M*N) for visited array for both ocean.
*/

// Clean code

class Solution {
public:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};

    void solve(vector<vector<int>>&arr, queue<pair<int,int>>&q, vector<vector<int>>&vis)
    {
        int m=arr.size(), n=arr[0].size();
        while(!q.empty())
        {
            int x = q.front().second;
            int y = q.front().first;
            q.pop();
            vis[y][x]=1;
            for(int k=0; k<4; k++)
            {
                int tx = dx[k]+x;
                int ty = dy[k]+y;
                if(tx>=0 && ty>=0 && tx<n && ty<m && arr[y][x]<=arr[ty][tx] && vis[ty][tx]==0)
                {
                    vis[ty][tx]=1;
                    q.push({ty, tx});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& arr) {
        int m=arr.size(), n=arr[0].size();
        vector<vector<int>>pac(m, vector<int>(n,0)), at(m, vector<int>(n,0)), ans;
        queue<pair<int,int>>q, r;
        for(int i=0; i<m; i++)
        {
            q.push({i,0});
            r.push({i,n-1});
        }
        for(int i=0; i<n; i++)
        {
            q.push({0,i});
            r.push({m-1,i});
        }

        solve(arr, q, pac);
        solve(arr, r, at);

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(pac[i][j] && at[i][j])
                    ans.push_back({i,j});
                    //cout<<i<<","<<j<<endl;
            }
        }
        return ans;
    }
};


// Similar code

class Solution {
public:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& arr) {
        int m=arr.size(), n=arr[0].size();
        vector<vector<int>>pac(m, vector<int>(n,0)), at(m, vector<int>(n,0)), ans;
        queue<pair<int,int>>q;
        for(int i=0; i<m; i++)
        {
            q.push({i,0});
        }
        for(int i=1; i<n; i++)
        {
            q.push({0,i});
        }
        while(!q.empty())
        {
            int x = q.front().second;
            int y = q.front().first;
            q.pop();
            pac[y][x]=1;
            for(int k=0; k<4; k++)
            {
                int tx = dx[k]+x;
                int ty = dy[k]+y;
                if(tx>=0 && ty>=0 && tx<n && ty<m && arr[y][x]<=arr[ty][tx] && pac[ty][tx]==0)
                {
                    pac[ty][tx]=1;
                    q.push({ty, tx});
                }
            }
        }

        for(int i=0; i<m; i++)
        {
            q.push({i,n-1});
        }
        for(int i=0; i<n-1; i++)
        {
            q.push({m-1,i});
        }
        while(!q.empty())
        {
            int x = q.front().second;
            int y = q.front().first;
            q.pop();
            at[y][x]=1;
            for(int k=0; k<4; k++)
            {
                int tx = dx[k]+x;
                int ty = dy[k]+y;
                if(tx>=0 && ty>=0 && tx<n && ty<m && arr[y][x]<=arr[ty][tx] && at[ty][tx]==0)
                {
                    at[ty][tx]=1;
                    q.push({ty, tx});
                }
            }
        }

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(pac[i][j] && at[i][j])
                    ans.push_back({i,j});
                    //cout<<i<<","<<j<<endl;
            }
        }
        return ans;
    }
};
