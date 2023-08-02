/*
Naive Approach to the problem can be to use a basic recursive function to go for
n-1 and n-2 and whatever the result comes out we can then add them to get the final
result..but it is time cosuming and will give TLE.

DP Approach --> we can apply memoisation because there are overlapping subproblems here 
and hence their result can be stored inside a DP array. This is top down approach.
Which can furthur be enhanced by bottom-up approach
*/

// Noob

class Solution {
public:
    
    int climb(int n)
    {
        if(n < 0) return 0;
        if(n == 1 || n == 0) return 1;

        return climb(n-1) + climb(n-2);
    }

    int climbStairs(int n) {
        return climb(n);
    }
};

// DP

class Solution {
public:
    
    int climb(vector<int>&dp, int n)
    {
        // if(n < 0) return 0;
        if(n == 1 || n == 0) return 1;
        if(dp[n] != -1) return dp[n];

        return dp[n] = climb(dp, n-1) + climb(dp, n-2);
    }

    int climbStairs(int n) {
        vector<int>dp(n+1, -1);
        return climb(dp, n);
    }
};