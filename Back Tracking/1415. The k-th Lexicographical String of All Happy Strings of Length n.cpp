/*
A happy string is a string that:

consists only of letters of the set ['a', 'b', 'c'].
s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.

Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.

Return the kth string of this list or return an empty string if there are less than k happy strings of length n.

Example 1:

Input: n = 1, k = 3
Output: "c"
Explanation: The list ["a", "b", "c"] contains all happy strings of length 1. The third string is "c".
Example 2:

Input: n = 1, k = 4
Output: ""
Explanation: There are only 3 happy strings of length 1.
Example 3:

Input: n = 3, k = 9
Output: "cab"
Explanation: There are 12 different happy string of length 3 ["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"]. 
You will find the 9th string = "cab" 

Constraints:

1 <= n <= 10
1 <= k <= 100

  */

// Brute force Back tracking
// We generate all string lexicographically(so sorting not neede).
/* T.C- n*2^n    n is the time needed to store a string; For n length of string we have in first place 3 option (a,b,c) for adjacent position we have only 2 
option because adjacent cannot be same. So  3*2*2*2*....n-1 times  => 3*2^n-1 => 3/2(2^n)  => 2^n [since 3/2 is constant]
  */
// Space- n*2^n + O(n) for recursion stack ; a string is of length n so 2^n string will take n*2^n

class Solution {
public:
    void solve(string cur, vector<string>&ans, int n)
    {
        if(cur.length()==n)
        {
            ans.push_back(cur);
            return;
        }
        for(char ch='a'; ch<='c'; ch++)
        {
            if(cur.length()!=0 && cur.back()==ch)
                continue;
            cur.push_back(ch);
            solve(cur, ans, n);
            cur.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        vector<string>ans;
        string cur="";
        solve(cur, ans, n);
        if(k>ans.size())
            return "";
        return ans[k-1];
    }
};


// Optimsation in above solution; we count number of string formed and if count==k then that is our answer. We dont need to store string in vector.
// T.C- 2^n
// Space- O(N) for recursion stack for height of recursion tree equal to length of string.
class Solution {
public:
    void solve(string cur, string&ans, int n, int k, int& count)
    {
        if(cur.length()==n)
        {
            count++;
            if(count==k)
                ans=cur;
            return;
        }
        for(char ch='a'; ch<='c'; ch++)
        {
            if(cur.length()!=0 && cur.back()==ch)
                continue;
            cur.push_back(ch);
            solve(cur, ans, n, k, count);
            cur.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        string cur="", ans="";
        int count=0;
        solve(cur, ans, n, k, count);
        if(k>count)
            return "";
        return ans;
    }
};
