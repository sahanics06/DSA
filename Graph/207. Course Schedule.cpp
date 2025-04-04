/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array 
prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. 
So it is impossible. 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.

  */


/*
Solution Using BFS
    We use the concept of indegeree. We create adjacentcy vector. We make a vector storing the indegrees for every node. 
    Insert nodes having indegree==0 in queue.

    Time- O(N+2E) ; N for queue will run for N nodes and for every node we will run for loop for its 
    indegree times. In graph total degree is 2E
    Space- O(N) for indegree vector, O(N) for queue. 
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& arr) {
        int n=arr.size();
        vector<int>d(numCourses,0);
        vector<vector<int>>adj(numCourses);
        for(int i=0; i<n; i++)
        {
            adj[arr[i][1]].push_back(arr[i][0]);
            d[arr[i][0]]++;
        }
        
        queue<int>q;
        for(int i=0; i<numCourses; i++)
        {
            if(d[i]==0)
                q.push(i);
        }
        if(q.empty())
            return false;

        while(!q.empty())
        {
            int tmp=q.front();
            cout<<tmp<<endl;
            q.pop();
            for(int i=0; i<adj[tmp].size(); i++)
            {
                int node = adj[tmp][i];
                d[node]--;
                if(d[node]==0)
                    q.push(node);
            }
        }

        for(int i=0; i<numCourses; i++)
        {
            if(d[i])
                return false;
        }
        return true;
    }
};
