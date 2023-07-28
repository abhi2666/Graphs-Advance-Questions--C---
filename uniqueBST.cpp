/*
2nCn/n+1 -- > catalan's Number
*/

// class Solution {
// public:

//     long long fact(int n){
//         long long ans = 1;
//         while(n--){
//             ans *= n;
//         }
//         return ans;
//     }
//     int numTrees(int n) {
//         int ans = (fact(2*n)/fact(n)*fact(n))/(n+1);
//         return ans;
//     }
// };

class Solution {
public:
    int solve(int n, vector<int>&dp)
    {
        if(n <= 1){
            return 1;
        }

        if(dp[n] != -1) return dp[n];
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            ans += solve(i - 1, dp) * solve(n - i, dp); 
        }
        return dp[n] = ans;
    }
    int numTrees(int n) {
        vector<int>dp(n+1, -1);
        return solve(n, dp);
    }
};