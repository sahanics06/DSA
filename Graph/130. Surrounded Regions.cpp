/*
You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells 
are on the edge of the board.
To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return 
anything.

Example 1:

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

Explanation:

In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

Example 2:

Input: board = [["X"]]

Output: [["X"]]

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] is 'X' or 'O'.

  */


/*
Solution using BFS, Here if 'O' is surrounded by 'X' then we change it to X. If 'O' can be connected to edge then it will
remain 'O'. So we first insert all O's at edge and then mark all connected O's to different character as they will not 
change to 'X'.

  Time- O(M*N) if all points are traversed
  Space- O(M*N) for queue; if all are O then it will get inserted in queue.
*/

class Solution {
public:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>>q;
        int m=board.size(), n=board[0].size();
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(board[i][j]=='O'&&(i==0||j==0||i==m-1||j==n-1))
                {
                    q.push({i,j});
                }
            }
        }

        while(!q.empty())
        {
            int x=q.front().second;
            int y=q.front().first;
            q.pop();
            board[y][x]='A';
            for(int k=0; k<4; k++)
            {
                int tx = x+dx[k];
                int ty = y+dy[k];
                if(tx>=0 && ty>=0 && tx<n && ty<m && board[ty][tx]=='O')
                {
                    q.push({ty,tx});
                    board[ty][tx]='A';
                }
            }
        }

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                //cout<<board[i][j]<<"  ";
                if(board[i][j]=='O')
                    board[i][j]='X';

                if(board[i][j]=='A')
                    board[i][j]='O';
                
            }
            //cout<<endl;
        }
    }
};


/*
Solution using DFS, same as BFS.
    Time- O(M*N)
    Space- O(M*N) dfs recursion stack
*/

class Solution {
public:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    void dfs(vector<vector<char>>&mat, int y, int x, int m, int n)
    {
        mat[y][x]='A';
        for(int k=0; k<4; k++)
        {
            int tx = x+dx[k];
            int ty = y+dy[k];
            if(tx>=0 && ty>=0 && tx<n && ty<m && mat[ty][tx]=='O')
            {
                dfs(mat, ty, tx, m, n);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>>q;
        int m=board.size(), n=board[0].size();
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(board[i][j]=='O'&&(i==0||j==0||i==m-1||j==n-1))
                {
                    dfs(board, i, j, m, n);
                }
            }
        }

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                //cout<<board[i][j]<<"  ";
                if(board[i][j]=='O')
                    board[i][j]='X';

                if(board[i][j]=='A')
                    board[i][j]='O';
                
            }
            //cout<<endl;
        }
    }
};
