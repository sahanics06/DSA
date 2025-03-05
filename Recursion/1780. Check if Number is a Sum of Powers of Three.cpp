Given an integer n, return true if it is possible to represent n as the sum of distinct powers of three. Otherwise, return false.
An integer y is a power of three if there exists an integer x such that y == 3x. 

Example 1:

Input: n = 12
Output: true
Explanation: 12 = 31 + 32
Example 2:

Input: n = 91
Output: true
Explanation: 91 = 30 + 32 + 34
Example 3:

Input: n = 21
Output: false

Constraints:

1 <= n <= 107

/*
Optimised approach- A number can be expressed as a sum of distinct powers of 3 if and only if its ternary representation(base 3)(similar to binary for 2, same process to find by dividing 
the number by base) consists of only 0s and 1s(i.e no digit should be 2). If 2 comes that means we have to use power of 3 two times which is not allowed, we can use power
of 3 only one time.
*/
class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n)
        {
            if(n%3>1)
                return false;
            n/=3;
        }
        return 1;
    }
};


/*
Brute force- using recursion, take the power or don take the power
T.C- O(2^lognbase3) since there are at max log n base3 steps to exceed n. power of 2 because we have taken or not_taken
Space- log n base 3 (recursion step)
*/
class Solution {
public:
    bool solve(int n, int power)
    {
        if(n==0)
            return true;
        bool taken=false, not_taken=false;
        if(n<pow(3, power))
            return false;
        taken = solve(n-pow(3, power), power+1);
        not_taken = solve(n, power+1);
        return taken||not_taken;
    }
    bool checkPowersOfThree(int n) {
        return solve(n, 0);
    }
};
