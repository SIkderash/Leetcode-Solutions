// https://leetcode.com/problems/count-sorted-vowel-strings

class Solution {
public:
    int countVowelStrings(int n) {
        int dp[50][5];
        for(int i=0; i<50; i++){
            for(int j=0; j<5; j++){
                if(i!=0) dp[i][j] = 0;
                else dp[i][j] = 1;
            }
        }
        if(n==1) return 5;
        int ans = 0;
        for(int i=1; i<n; i++){
            for(int j=0; j<5; j++){
                for(int k=0; k<=j; k++){
                    dp[i][j] += dp[i-1][k];
                }
                if(i==n-1) ans += dp[i][j];
                //cout << i << " " << dp[i][j] << " " << endl;
            }
        }
        return ans;
    }
};