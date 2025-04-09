/*
Given an array of strings strs, group all anagrams together into sublists. You may return the output in any order.

An anagram is a string that contains the exact same characters as another string, but the order of the characters can be 
different.

Example 1:

Input: strs = ["act","pots","tops","cat","stop","hat"]

Output: [["hat"],["act", "cat"],["stop", "pots", "tops"]]
Example 2:

Input: strs = ["x"]

Output: [["x"]]
Example 3:

Input: strs = [""]

Output: [[""]]
Constraints:

1 <= strs.length <= 1000.
0 <= strs[i].length <= 100
strs[i] is made up of lowercase English letters.

  */

/*
  Solution using map, for every string we create key using 26 characters and add that string with its key value in map.
  Then we traverse the map and store the anagrams.

  Time - N*K; N is size of string, K is max length of string and 26 for creating key
  Space - O(N)

  */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        vector<vector<string>>ans;
        for(int i=0; i<strs.size(); i++)
        {
            string tmp = strs[i];
            vector<int>count(26,0);
            for(int j=0; j<strs[i].length(); j++)
            {
                count[strs[i][j]-'a']++;
            }
            string key="";
            for(int j=0;j<26; j++)
            {
                if(count[j])
                    key+= to_string(count[j])+to_string('a'+j); // directly cannot add two characters, adding two characters give ASCII value
            }
            mp[key].push_back(strs[i]);
        }
        for(auto it:mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};


/*
Solution same as above but for key we use string

  Time- N*KlogK ; KlogK for sorting string of length K
  Space- N

  */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        vector<vector<string>>ans;
        for(int i=0; i<strs.size(); i++)
        {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            mp[tmp].push_back(strs[i]);
        }
        for(auto it:mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};
