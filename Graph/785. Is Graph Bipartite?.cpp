/*
There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. 
You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, 
for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following 
properties:

There are no self-edges (graph[u] does not contain u).
There are no parallel edges (graph[u] does not contain duplicate values).
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the 
graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.

Example 1:

Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
Output: false
Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a 
node in one and a node in the other.
Example 2:

Input: graph = [[1,3],[0,2],[1,3],[0,2]]
Output: true
Explanation: We can partition the nodes into two sets: {0, 2} and {1, 3}.
 
Constraints:

graph.length == n
1 <= n <= 100
0 <= graph[u].length < n
0 <= graph[u][i] <= n - 1
graph[u] does not contain u.
All the values of graph[u] are unique.
If graph[u] contains v, then graph[v] contains u.
*/

/*
Solution using BFS, we have to find whether we can color the graph with two color such that no two adjacent node
have same color. Here we initially marked visisted as -1 and two colors as 0 and 1.
    Time - O(V+E) we traverse every vertex and traverse every edge once.
    SPace - O(V), for color array and at max all vertex can be in queue.
*/

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        
        queue<int>q;
        vector<int>vis(n,-1);
        for(int i=0; i<n; i++)
        {
            if(vis[i]==-1)
            {
                q.push(i);
                while(!q.empty())
                {
                    int node = q.front();
                    q.pop();
                    for(int i=0; i<graph[node].size(); i++)
                    {
                        int cur = graph[node][i];
                        if(vis[cur]==-1)
                        {
                            vis[cur]=!vis[node];
                            q.push(cur);
                        }
                        else if(vis[cur]==vis[node])
                        {
                            return false;
                        }
                    }

                }
                
            }
        }
        return true;
    }
};


/*
Solution using DFS
  Time - O(V+E) to traverse all the edges for every node
  Space - O(V) for vis array and recursion stack O(V) at worst case height of recursion tree can be N skew tree
*/

class Solution {
public:
    bool dfs(vector<vector<int>>&adj, int node, int color, vector<int>&vis)
    {
        vis[node]=color;
        for(int i=0; i<adj[node].size(); i++)
        {
            int cur=adj[node][i];
            if(vis[cur]==-1)
            {
                if(!dfs(adj, cur, !color, vis))
                    return false;
            }
            else if(vis[cur]==color)
            {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        
        vector<int>vis(n,-1);
        for(int i=0; i<n; i++)
        {
            if(vis[i]==-1)
            {
                if(!dfs(graph, i, 0, vis))                
                    return false;
            }
        }
        return true;
    }
};
