/*
Given an array of integers arr[], the task is to find the maximum of the minimum values for every possible window size in 
the array, where the window size ranges from 1 to arr.size().

More formally, for each window size k, determine the smallest element in all windows of size k, and then find the largest 
value among these minimums where 1<=k<=arr.size().

Examples :

Input: arr[] = [10, 20, 30, 50, 10, 70, 30]
Output: [70, 30, 20, 10, 10, 10, 10] 
Explanation: 
1. First element in output indicates maximum of minimums of all windows of size 1. Minimums of windows of size 1 are [10], 
[20], [30], [50], [10], [70] and [30]. Maximum of these minimums is 70. 
2. Second element in output indicates maximum of minimums of all windows of size 2. Minimums of windows of size 2 are [10], 
[20], [30], [10], [10], and [30]. Maximum of these minimums is 30. 
3. Third element in output indicates maximum of minimums of all windows of size 3. Minimums of windows of size 3 are [10], 
[20], [10], [10] and [10]. Maximum of these minimums is 20. 
Similarly other elements of output are computed.
Input: arr[] = [10, 20, 30]
Output: [30, 20, 10]
Explanation: First element in output indicates maximum of minimums of all windows of size 1. Minimums of windows of size 1 
are [10] , [20] , [30]. Maximum of these minimums are 30 and similarly other outputs can be computed
Constraints:
1 <= arr.size() <= 105
1 <= arr[i] <= 106

*/

/*
Optimised solution- Here we find the indexes of left smallest element and right smallest element for every element.
Then we find the size of window the element is smaller by right[i]-left[i]. To find  left and right smaller indexes 
we use stack. In stack if we see that top element is latger than present element then we keep on popping else we put in 
stack. Then we put the element at the extreme 
point of window size so that no other element can be the answer. Atlast we update the smaller size window answer.
*/

class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        // Your code here
        int n=arr.size();
        vector<int>ans(n,0), left(n,0), right(n,0);
        stack<int>st, s;
        for(int i=0; i<n; i++)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                left[i]=st.top();
            }
            else
            {
                left[i]=-1;
            }
            st.push(i);
        }
        for(int i=n-1; i>=0; i--)
        {
            while(!s.empty() && arr[s.top()]>=arr[i])
            {
                s.pop();
            }
            if(!s.empty())
            {
                right[i]=s.top();
            }
            else
            {
                right[i]=n;
            }
            s.push(i);
        }
        for(int i=0; i<n; i++)
        {
            //cout<<right[i]-left[i]<<"  "<<arr[i]<<endl;
            ans[right[i]-left[i]-2]=max( ans[right[i]-left[i]-2], arr[i]);
            //cout<<ans[i]<<endl;
        }
        for(int i=n-2; i>=0; i--)
        {
            ans[i] = max(ans[i+1], ans[i]);
        }
        return ans;
    }
};

/* Brute Force- Here we iterate for every size in outer loop then we use two loop to iterate and find maximum of minimum 
for every size subarray and update in ans.
T.C- O(N^3)
Space- O(N) answer vector
*/

class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        // Your code here
        int n=arr.size();
        vector<int>ans(n,0);
        for(int i=1; i<=n; i++)
        {
            int mx=INT_MIN;
            for(int j=0; j<n; j++)
            {
                int tmp=INT_MAX;
                for(int k=j; k<j+i; k++)
                {
                    tmp = min(tmp, arr[k]);
                }
                mx= max(mx, tmp);
            }
            if(ans[i-1]<mx)
            {
                ans[i-1] = mx;
            }
        }
        return ans;
    }
};

/* Brute Force- Here we find the size of windows for every element and store at last index of its range. Then if new elements
enters we check if it is larger than the earlier element then we update it. Then at last we might have indexes with empty 
values which we will update with the right side elements because that is the element which has higher range.

T.C- O(N^2)
Space- O(N) 
*/



class Solution {
  public:
    int right(vector<int>&arr, int i)
    {
        for(int k=i+1; k<arr.size(); k++)
        {
            if(arr[k]<arr[i])
                return k;
        }
        return arr.size();
    }
    
    int left(vector<int>&arr, int i)
    {
        for(int k=i-1; k>=0; k--)
        {
            if(arr[k]<arr[i])
                return k;
        }
        return -1;
    }
    vector<int> maxOfMins(vector<int>& arr) {
        // Your code here
        int n = arr.size();
        vector<int>ans(n,0);
        for(int i=0; i<n; i++)
        {
            int l = left(arr, i);
            int r = right(arr, i);
            //cout<<l<<"  "<<arr[i]<<"  "<<r<<"  "<<r-l<<endl;
            if(ans[r-l-2]<arr[i])
                ans[r-l-2]=arr[i];
        }
        for(int i=n-2; i>=0; i--)
        {
            if(ans[i+1]>ans[i])
                ans[i]=ans[i+1];
        }
        return ans;
    }
};
