/*
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}

Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, 
the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of 
neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the 
cloned graph.

Example 1:

Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
Example 2:

Input: adjList = [[]]
Output: [[]]
Explanation: Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does not 
have any neighbors.
Example 3:

Input: adjList = []
Output: []
Explanation: This an empty graph, it does not have any nodes.
 

Constraints:

The number of nodes in the graph is in the range [0, 100].
1 <= Node.val <= 100
Node.val is unique for each node.
There are no repeated edges and no self-loops in the graph.
The Graph is connected and all nodes can be visited starting from the given node.
  */

/*
Solution. Here we have called a recursion function every time a new node was created. And we use a map to track the initial 
node and new nodes so that when the node was created earlier then we can just insert the neighbors into it.

  Time- O(V+E) we traverse every node and edges once
  Space- O(V) as map stores all values of vertives and recursion might need for all the nodes.
  */

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void solve(Node* node, unordered_map<Node*, Node*>&mp, Node* head)
    {
        if(mp.find(node)!=mp.end())
            return ;
        mp[node]=head;
        for(auto neighbor:node->neighbors)
        {
            if(mp.find(neighbor)==mp.end())
            {
                Node *tmp = new Node(neighbor->val);
                head->neighbors.push_back(tmp); //push the new neighbors into head
                solve(neighbor, mp, tmp);
            }
            else
            {
                head->neighbors.push_back(mp[neighbor]); /*  if a node is created then here we only have to push the 
                neighbors which was stored in map. */
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        unordered_map<Node*, Node*>mp;   /* we store the nodes with new nodes so that we can use it to push into 
      neighbors vector*/
        Node* head = new Node(node->val);
        solve(node, mp, head);
        return head;
    }
};

// Solution using BFS

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        unordered_map<Node*, Node*>mp; // we store the nodes with new nodes so that we can use it to push into neighbors vector
        queue<Node*>q;
        Node* head = new Node(node->val);
        mp[node]=head;  // store the new node
        q.push(node);
        while(!q.empty())
        {
            Node *cur = q.front();
            q.pop();
            for(auto neighbor:cur->neighbors)
            {
                if(mp.find(neighbor)==mp.end())
                {
                    Node* next = new Node(neighbor->val);
                    mp[neighbor] = next;
                    q.push(neighbor);
                }
                mp[cur]->neighbors.push_back(mp[neighbor]); // add neighbors to present new node
            }            
        }
        return head;
    }
};
