// https://leetcode.com/problems/count-sorted-vowel-strings

class Solution {
public:
    int countVowelStrings(int n) {
        int dp[55][5];
        memset(dp,0,sizeof dp);
        
        for(int i=0;i<5; i++)
            dp[1][i] = 1;
        
        for(int i=2; i<=50; i++){
            for(int j=0; j<5; j++){
                for(int k=0; k<=j; k++){
                    dp[i][j] += dp[i-1][k];
                }
                cout << i << " " << j << " " << dp[i][j] << endl; 
            } 
        }
        int ans=  0;
        for(int i=0; i<5; i++){
            ans += dp[n][i]; 
        }
        
        return ans;
    }
};