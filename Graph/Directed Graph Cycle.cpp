/*Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge from verticex u to v.

Examples:

Input: V = 4, edges[][] = [[0, 1], [1, 2], [2, 3], [3, 3]]

Output: true
Explanation: 3 -> 3 is a cycle
Input: V = 3, edges[][] = [[0, 1], [1, 2]]

Output: false
Explanation: no cycle in the graph
Constraints:
1 ≤ V, E ≤ 105

  */

/*
Solution using DFS, We create vector visited and path, in visited with mark every node that is visited so that we dont keep
on traversing same node repeated time. In path we mark as 1 when visited and if while traversing a node if we see that
visited is marked 1 and path is already marked as 1 then that node is visted by some other node so that means CYCLE present.
  When dfs is over then we mark path as 0 because from different node also we can come to same node but that may not be cycle.

    Time- O(V+E); We traverse every node and edge once; also in for loop we check if visited[i]==0 then we call dfs so
          overall O(V+E).
    Space- O(V+E) for adjacency list, O(V) for visisted and path array
*/

class Solution {
  public:
    bool dfs(vector<vector<int>>&adj, vector<int>&vis, vector<int>&path, int node)
    {
        vis[node]=1;
        path[node]=1;
        for(int i=0; i<adj[node].size(); i++)
        {
            int tmp = adj[node][i];
            if(vis[tmp]==0)
            {
                if(dfs(adj, vis, path, tmp))
                    return true;
            }
            else if(path[tmp]!=-1)
                return true;
        }
        path[node]=-1;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj(V);
        vector<int>path(V,-1), vis(V,0);
        int c=0;
        for(int i=0; i<edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        for(int i=0; i<V; i++)
        {
            if(vis[i]==0)
            {
                if(dfs(adj, vis, path, i))
                    return true;
            }
        }
        return false;
    }
};


/*
  Solution using BFS, Kahn's Algorithm. Using topological sort. If size of topo vector==number of vertex then there is no cycle else 
    Topological sort is not possible in cyclic graph so cycle is present.
    We create a vector to store indegree of every nodes. We push every node whose indegree is 0. We traverse queue and keep
    on decreasing indegree of neighboring node and keep on pushing node whose indegree is 0. We can use count variable
    or push topo vector to keep trakc of node in the topological sort. If size of topo vector or count not equal to
    size of vertex then cycle is present.

    Time - O(V+E) for traversing each vertex and edge
    Space - O(V) for pushing V vertex in queue at worst, topo vector size V.
*/

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj(V);
        vector<int>path(V,-1), vis(V,0), indegree(V,0), topo;
        queue<int>q;
        int c=0;
        for(int i=0; i<edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        for(int i=0; i<V; i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        
        while(!q.empty())
        {
            int node = q.front();
            topo.push_back(node);
            q.pop();
            for(int i=0; i<adj[node].size(); i++)
            {
                int neighbor = adj[node][i];
                indegree[neighbor]--;
                if(indegree[neighbor]==0)
                {
                    q.push(neighbor);
                }
            }
        }
        
        return topo.size()!=V;
    }
};
