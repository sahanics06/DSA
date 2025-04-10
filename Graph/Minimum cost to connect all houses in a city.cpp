/*
Given a 2D array houses[][], consisting of n 2D coordinates {x, y} where each coordinate represents the location of 
each house, the task is to find the minimum cost to connect all the houses of the city.

The cost of connecting two houses is the Manhattan Distance between the two points (xi, yi) and (xj, yj) 
i.e., |xi – xj| + |yi – yj|, where |p| denotes the absolute value of p.

Examples :

Input: n = 5 houses[][] = [[0, 7], [0, 9], [20, 7], [30, 7], [40, 70]]
Output: 105
Explanation:
Connect house 1 (0, 7) and house 2 (0, 9) with cost = 2
Connect house 1 (0, 7) and house 3 (20, 7) with cost = 20
Connect house 3 (20, 7) with house 4 (30, 7) with cost = 10 
At last, connect house 4 (30, 7) with house 5 (40, 70) with cost 73.
All the houses are connected now.
The overall minimum cost is 2 + 10 + 20 + 73 = 105.

Input: n = 4 houses[][] = [[0, 0], [1, 1], [1, 3], [3, 0]]
Output: 7
Explanation: 
Connect house 1 (0, 0) with house 2 (1, 1) with cost = 2
Connect house 2 (1, 1) with house 3 (1, 3) with cost = 2 
Connect house 1 (0, 0) with house 4 (3, 0) with cost = 3 
The overall minimum cost is 3 + 2 + 2 = 7.
Constraint:
1 ≤ n ≤ 103
0 ≤ houses[i][j] ≤ 103

*/

/*Using Minimum Spanning Tree, using priority_queue, visisted arrray. We can se it as undirected graph.
  Here we are given coordinates of every houses, so we create an adjacency list for every node to every node
with its weight as manhattan distance. Then we apply MST approach. If node visited then continue else
push in pq its weight and node. We dont mark visited[node]=1 when traversing from source node in the for loop. 
  We mark vis[node]=1 when it comes from pq because there may be possibility that same node is reached from different
source node and its weight can be lesser. So in Min heap PQ the one with lesser nodes comes first.
  */

class Solution {
  public:
  typedef pair<int,int> pr;
    int minCost(vector<vector<int>>& houses) {
        // code here
        int n=houses.size(), ans=0;
        vector<int>vis(n,0);
        vector<vector<pr>>adj(n);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==j)
                    continue;
                
                int d = abs(houses[i][0]-houses[j][0])+abs(houses[i][1]-houses[j][1]);
                adj[i].push_back({j,d});
                //adj[j].push_back({i,d}); Dont need this step because for every node we are calculating the 
              // distance to other node. So copies will get inserted. ex- i=0, j=1; 
              // adj[0].push_back(1); adj[1].push_back(0) ; when i=1, j=0; adj[1].push_back(0); adj[0].push_back(1);
            }
        }
        
        pq.push({0,0});
        
        while(!pq.empty())
        {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(vis[node])
                continue;
            vis[node]=1;
            ans+=d;
            
            for(int i=0; i<adj[node].size(); i++)
            {
                int cur = adj[node][i].first;
                int w = adj[node][i].second;
                pq.push({w,cur});
            }
        }
        return ans;
    }
};
