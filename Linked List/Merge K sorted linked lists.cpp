/*
Given an array arr[] of n sorted linked lists of different sizes. The task is to merge them in such a way that after merging they will be a single sorted linked list, 
then return the head of the merged linked list.

Examples:

Input: arr[] = [1 -> 2 -> 3, 4 -> 5, 5 -> 6, 7 -> 8]
Output: 1 -> 2 -> 3 -> 4 -> 5 -> 5 -> 6 -> 7 -> 8
Explanation:
The arr[] has 4 sorted linked list of size 3, 2, 2, 2.
1st list: 1 -> 2-> 3
2nd list: 4 -> 5
3rd list: 5 -> 6
4th list: 7 -> 8
The merged list will be:
 
Input: arr[] = [1 -> 3, 8, 4 -> 5 -> 6]
Output: 1 -> 3 -> 4 -> 5 -> 6 -> 8
Explanation:
The arr[] has 3 sorted linked list of size 2, 3, 1.
1st list: 1 -> 3
2nd list: 8
3rd list: 4 -> 5 -> 6
The merged list will be:

Constraints
1 <= total no. of nodes <= 105
1 <= node->data <= 103

  */

// Brute force
// We take each list and merge them 2 at a time.
// T.C- O(N*K*K) if we take n as size of every list, so the comparisions will be n+2n+3n+4n...+nk = N*KK
// Space- O(1)

class Solution {
  public:
    Node* solve(Node *a, Node* b)
    {
        Node* ans = new Node(0);
        Node* tmp = ans;
        while(a && b)
        {
            if(a->data <=b->data)
            {
                tmp->next=a;
                a=a->next;
            }
            else
            {
                tmp->next=b;
                b=b->next;
            }
            tmp=tmp->next;
        }
        if(a)
        {
            tmp->next=a;
        }
        if(b)
        {
            tmp->next=b;
        }
        return ans->next;
    }
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        if(arr.size()==1)
            return arr[0];
        Node *ans = arr[0];
        for(int i=1; i<arr.size(); i++)
        {
            ans = solve(ans, arr[i]);
        }
        return ans;
    }
};
