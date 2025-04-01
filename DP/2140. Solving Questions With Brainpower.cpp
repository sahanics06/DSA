/*
You are given a 0-indexed 2D integer array questions where questions[i] = [pointsi, brainpoweri].

The array describes the questions of an exam, where you have to process the questions in order (i.e., starting from question 0) and make a decision whether to solve or skip each question. Solving question i will earn you pointsi points but you will be unable to solve each of the next brainpoweri questions. If you skip question i, you get to make the decision on the next question.

For example, given questions = [[3, 2], [4, 3], [4, 4], [2, 5]]:
If question 0 is solved, you will earn 3 points but you will be unable to solve questions 1 and 2.
If instead, question 0 is skipped and question 1 is solved, you will earn 4 points but you will be unable to solve questions 2 and 3.
Return the maximum points you can earn for the exam.

 

Example 1:

Input: questions = [[3,2],[4,3],[4,4],[2,5]]
Output: 5
Explanation: The maximum points can be earned by solving questions 0 and 3.
- Solve question 0: Earn 3 points, will be unable to solve the next 2 questions
- Unable to solve questions 1 and 2
- Solve question 3: Earn 2 points
Total points earned: 3 + 2 = 5. There is no other way to earn 5 or more points.
Example 2:

Input: questions = [[1,1],[2,2],[3,3],[4,4],[5,5]]
Output: 7
Explanation: The maximum points can be earned by solving questions 1 and 4.
- Skip question 0
- Solve question 1: Earn 2 points, will be unable to solve the next 2 questions
- Unable to solve questions 2 and 3
- Solve question 4: Earn 5 points
Total points earned: 2 + 5 = 7. There is no other way to earn 7 or more points.
 

Constraints:

1 <= questions.length <= 105
questions[i].length == 2
1 <= pointsi, brainpoweri <= 105
  */

/*

/*
Optimised Bottom up appoarch, Tabular
Here we can see that answer for a index depends on the future answers. So we have to loop backwards. 
If jumps from ith index is less than n then we add the answer of that index to the profit of ith index.
If we skip present index then the answer can be next index.

*/

// More cleaner code then the below bottom up
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long>dp(n+1, 0);// we took n+1 because we are looking i+1 index also in the loop.
        for(int i=n-1; i>=0; i--)
        {
            long long jumps = 0, tmp=0;
            
            jumps = min(questions[i][1]+1+i, n); // if jumps>n then jumps =n and dp[n]=0; Avoiding if statement
            
            tmp = dp[i+1];// if we skip this index then solution can be next index
            dp[i] = max(tmp, dp[jumps]+questions[i][0]);
        }
        return dp[0];
    }
};

//------------------------------


class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long>dp(n, 0);
        for(int i=n-1; i>=0; i--)
        {
            long long jumps = 0, tmp=0;
            if(questions[i][1]+1+i<n)
            {
                jumps = dp[questions[i][1]+1+i];
            }
            if(i<n-1)
                tmp = dp[i+1];// if we skip this index then solution can be next index
            dp[i] = max(tmp, jumps+questions[i][0]);
        }
        return dp[0];
    }
};


Solution- Using recursion and memoization.
  We take and not take, when taken we pass the next index which is the index that we can take after skipping 
the between steps, this reduces useless recursion call of not taking the in between steps, So only index is 
variable here.
  Time - O(N)
  Space- O(N) dp vector
*/

class Solution {
public:
    long long solve(vector<vector<int>>&arr, vector<long long>&dp, int i)
    {
        if(i>=arr.size())
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        long long taken=0, not_taken=0;
        
        taken = arr[i][0] + solve(arr, dp, i+arr[i][1]+1);
        not_taken = solve(arr, dp, i+1);
        
        return dp[i] = max(taken, not_taken);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long>dp(n, -1);
        return solve(questions, dp, 0);
    }
};
