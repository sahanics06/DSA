/*
Given an undirected, weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by 2d array edges[][], 
where edges[i]=[u, v, w] represents the edge between the nodes u and v having w edge weight.
You have to find the shortest distance of all the vertices from the source vertex src, and return an array of integers 
where the ith element denotes the shortest distance between ith node and source vertex src.

Note: The Graph is connected and doesn't contain any negative weight edge.

Examples:

Input: V = 3, edges[][] = [[0, 1, 1], [1, 2, 3], [0, 2, 6]], src = 2
Output: [4, 3, 0]
Explanation:

Shortest Paths:
For 2 to 0 minimum distance will be 4. By following path 2 -> 1 -> 0
For 2 to 1 minimum distance will be 3. By following path 2 -> 1
For 2 to 2 minimum distance will be 0. By following path 2 -> 2
Input: V = 5, edges[][] = [[0, 1, 4], [0, 2, 8], [1, 4, 6], [2, 3, 2], [3, 4, 10]], src = 0
Output: [0, 4, 8, 10, 10]
Explanation: 

Shortest Paths: 
For 0 to 1 minimum distance will be 4. By following path 0 -> 1
For 0 to 2 minimum distance will be 8. By following path 0 -> 2
For 0 to 3 minimum distance will be 10. By following path 0 -> 2 -> 3 
For 0 to 4 minimum distance will be 10. By following path 0 -> 1 -> 4
Constraints:
1 ≤ V ≤ 105
1 ≤ E = edges.size() ≤ 105
0 ≤ edges[i][j] ≤ 104
0 ≤ src < V
  */

/*
Solution using BFS, Priority queue. We store INT_MAX initially for every node. Then we start from source and keep pushing
weight and node if cur distance<previous distance. We use priority queue because it gives the most efficient answer and
voids from updating distance for a node for multiple time. If we use normal queue then we might have to update every node
multiple times which will lead to E*V time complexity.

    Time - VlogE; for V vertex we might need to push all edges and poping costs logE time.
    Space - V+E for adj list, V for answer array, V for pq at worst all vertex in queue.
  */

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>>adj(V);
        vector<int>ans(V,INT_MAX);
        ans[src]=0;
        for(int i=0; i<edges.size(); i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,src});
        
        while(!pq.empty())
        {
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(int i=0; i<adj[node].size(); i++)
            {
                int cur=adj[node][i].first;
                int w=adj[node][i].second;
                if(ans[cur]>w+d)
                {
                    ans[cur]=w+d;
                    pq.push({w+d, cur});
                }
            }
        }
        return ans;
    }
};
