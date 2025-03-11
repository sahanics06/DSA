/*
You are given a string word and a non-negative integer k.

Return the total number of substrings of word that contain every vowel ('a', 'e', 'i', 'o', and 'u') at least once and 
exactly k consonants. 

Example 1:

Input: word = "aeioqq", k = 1

Output: 0

Explanation:

There is no substring with every vowel.

Example 2:

Input: word = "aeiou", k = 0

Output: 1

Explanation:

The only substring with every vowel and zero consonants is word[0..4], which is "aeiou".

Example 3:

Input: word = "ieaouqqieaouqq", k = 1

Output: 3

Explanation:

The substrings with every vowel and one consonant are:

word[0..5], which is "ieaouq".
word[6..11], which is "qieaou".
word[7..12], which is "ieaouq".

Constraints:

5 <= word.length <= 2 * 105
word consists only of lowercase English letters.
0 <= k <= word.length - 5
  */

/*
Solution using sliding window. Here we use i and j and count vowels and consonent. Here we have use a vector to find the next
consonent because if we find a window which satisfies the conditions then that window satisfies condition for all window 
until we find next consonent. If consonent>k then we shrink.

T.C- O(N)
Space- O(N) vector to track next consonent.
*/

class Solution {
public:
    typedef long long ll;
    bool vowel(char s)
    {
        if(s=='a'||s=='e'||s=='i'||s=='o'||s=='u')
            return true;
        return false;
    }
    long long countOfSubstrings(string s, int k) {
        unordered_map<char,int>mp;
        int n=s.length();
        ll ans=0;
        vector<int>tmp(n+1,n);
        int t=n, i=0, j=0, c=0;
        for(int i=n-1; i>=0; i--)
        {
            if(!vowel(s[i]))
            {
                tmp[i]=t;
                t=i;
            }  
            else 
                tmp[i]=t;
        }
        while(i<n)
        {
            if(vowel(s[i]))
            {
                mp[s[i]]++;
            }
            else
            {
                c++;
            }
            while(c>k)
            {
                if(vowel(s[j]))
                {
                    mp[s[j]]--;
                    if(mp[s[j]]==0)
                        mp.erase(s[j]);
                }
                else
                {
                    c--;
                }
                j++;
            }
            if(c==k && mp.size()==5)
            {
                while(c==k && mp.size()==5 && j<i)
                {
                    ans+=(tmp[i]-i);
                    if(vowel(s[j]))
                    {
                        mp[s[j]]--;
                        if(mp[s[j]]==0)
                            mp.erase(s[j]);
                    }
                    else
                    {
                        c--;
                    }
                    j++;
                }                
            }
            i++;
        }
        return ans;
    }
};

/*
Brute Force Solution- Going through every substring and checking count of consosnent and vomels.
  T.C- O(N^N)
  Space- O(1)
*/

class Solution {
public:
    typedef long long ll;
    long long countOfSubstrings(string s, int k) {
        ll ans=0;
        int n=s.length();
        for(int i=0; i<n; i++)
        {
            int v=0, c=0;
            unordered_map<char,int>mp;
            for(int j=i; j<n; j++)
            {
                if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u')
                {
                    mp[s[j]]++;
                }
                else
                {
                    c++;
                }
                if(mp.size()==5 && c==k)
                {
                    ans++;
                }
                if(c>k)
                    break;
            }
        }
        return ans;
    }
};
