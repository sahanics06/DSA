/*
Given a weighted, undirected, and connected graph with V vertices and E edges, your task is to find the sum of the weights 
of the edges in the Minimum Spanning Tree (MST) of the graph. The graph is represented by an adjacency list, where each 
element adj[i] is a vector containing vector of integers. Each vector represents an edge, with the first integer denoting 
the endpoint of the edge and the second integer denoting the weight of the edge.

Input:
3 3
0 1 5
1 2 3
0 2 1

Output: 4
Explanation:

The Spanning Tree resulting in a weight
of 4 is shown above.
Input: 
2 1
0 1 5

Output: 5 

Explanation: Only one Spanning Tree is possible which has a weight of 5.
Constraints:
2 ≤ V ≤ 1000
V-1 ≤ E ≤ (V*(V-1))/2
1 ≤ w ≤ 1000
The graph is connected and doesn't contain self-loops & multiple edges.

  */

/*
Solution using min heap priority queue, we store weight and source node in pq. if visited[source] then continue else
 add weight to answer and push in pq its weight and nodes.

 Time - ElogE ; At worst all edges can be in pq. for every pop it takes logE time
 Space - O(V) ; at nodes all vertex are in pq

*/

class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,0});
        int ans=0;
        vector<int>vis(V,0);
        while(!pq.empty())
        {
            int source = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            if(vis[source])
                continue;
            ans+=d;
            vis[source]=1;
            for(int i=0; i<adj[source].size(); i++)
            {
                int node = adj[source][i][0];
                int w = adj[source][i][1];
                
                pq.push({w, node});
            }
        }
        return ans;
    }
};
