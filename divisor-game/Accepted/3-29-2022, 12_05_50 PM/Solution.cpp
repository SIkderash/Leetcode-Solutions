// https://leetcode.com/problems/divisor-game

class Solution {
public:
    bool divisorGame(int n) {
        int dp[1005];
        dp[0] = 0, dp[1] = 0;
        for(int i=0; i<=n; i++) dp[i] = 0;
        for(int i=2; i<=n; i++){
            for(int j=1; j<i; j++){
                if(i%j==0) dp[i] |= (dp[i-j]==0);
            }
        }
        return dp[n];
    }
};