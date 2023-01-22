// https://leetcode.com/problems/palindromic-substrings

class Solution {
public:
    bool dp[1001][1001];
    int countSubstrings(string s) {
        int n = s.length(), cnt = 0;   
        for(int i=0; i<n; i++){
            dp[i][i] = 1;
            if(i+1<n && s[i]==s[i+1]){
                dp[i][i+1] = 1;
                cnt++;
            }
        }
        for(int l=3; l<=n; l++){
            for(int i=0; i<n; i++){
                int j = i+l-1;
                if(j>=n) break;
                dp[i][j] = (s[i]==s[j]) & (dp[i+1][j-1]);
                if(dp[i][j]) cnt++;
            }
        }
        return n + cnt;
    }
};