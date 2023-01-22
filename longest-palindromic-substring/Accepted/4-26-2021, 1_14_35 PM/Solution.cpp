// https://leetcode.com/problems/longest-palindromic-substring


class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        bool dp[n][n];
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(i==j){
                    dp[i][j] = true;
                }
                else{
                    dp[i][j] = false;
                }
                if(j==i+1){
                    if(s[i]==s[j]){
                        dp[i][j] = true;
                    }
                    else{
                        dp[i][j] = false;
                    }
                }
            }
        }
        for(int l=3; l<=n; l++){
            for(int i=0; i<n; i++){
                int j = i+l-1;
                if(j<n && s[i]==s[j] && dp[i+1][j-1]==true){
                    dp[i][j] = true;
                }
            }
        }
        int len = 0, left_end = 0, right_end = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(dp[i][j] && j-i+1>len){
                    left_end = i;
                    len = j-i+1;
                }
            }
        }
        string ans = s.substr(left_end, len);
        return ans;
    }
};