// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    int maxi = 0, maxj = 0, max = -1;
    string s;
    string longestPalindrome(string input) {
        int dp[1005][1005];
        s = input;
        int n = s.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dp[i][j] = -1;
            }
        }
        recur(0,n-1, dp);
        cout << max << " " << maxi << " " << maxj << endl;
        string ans = "";
        for(int i = maxi; i<=maxj; i++) ans += s[i];
        return ans;
    }
    int recur(int i, int j, int (&dp)[1005][1005]){
        if(i>=j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]){
            dp[i][j] = recur(i+1, j-1, dp);
        }
        else{
            dp[i][j]=0;
        }
        if(dp[i][j]==1){
            if(j-i>max){
                maxi = i;
                maxj = j;
                max = j-i;
            }
        }
        else {
            recur(i+1, j, dp);
            recur(i, j-1, dp);
        }
        
        //cout << i << " " << j << " " << dp[i][j] << endl;
        return dp[i][j];
    }
};