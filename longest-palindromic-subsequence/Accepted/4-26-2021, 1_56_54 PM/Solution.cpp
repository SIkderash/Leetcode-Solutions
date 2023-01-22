// https://leetcode.com/problems/longest-palindromic-subsequence

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string text1 = s;
        string text2 = s;
        reverse(text2.begin(), text2.end());
        int n = text1.length();
        int m = text2.size();
        int dp[n+1][m+1];
        int mp[n];
        memset(mp,-1,sizeof mp);
        
        for(int i=0; i<=n; i++) dp[i][0] = 0;
        for(int i=0; i<=m; i++) dp[0][i] = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(text1[i]==text2[j]){
                    dp[i+1][j+1] = 1+ dp[i][j];
                    if(mp[i]==-1) mp[i] = j;
                }
                else{
                    dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        string ans = "";
        for(int i=0; i<n; i++){
            if(mp[i]!=-1) {
                ans += text2[mp[i]];
            }
        }
        cout << ans.size();
        return dp[n][m];
    }
};