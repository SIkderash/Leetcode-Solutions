// https://leetcode.com/problems/longest-common-subsequence

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.size();
        int dp[n+1][m+1];
        set<int> s;
        for(int i=0; i<=n; i++) dp[i][0] = 0;
        for(int i=0; i<=m; i++) dp[0][i] = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(text1[i]==text2[j]){
                    dp[i+1][j+1] = 1+ dp[i][j];
                    s.insert(i);
                }
                else{
                    dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        /*string ans = "";
        for(auto c : s){
            ans += c;
        }*/
        return dp[n][m];
    }
};