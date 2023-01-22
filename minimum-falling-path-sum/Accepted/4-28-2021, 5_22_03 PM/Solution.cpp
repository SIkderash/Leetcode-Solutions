// https://leetcode.com/problems/minimum-falling-path-sum

class Solution {
public:
    int dp[105][105];
    int minFallingPathSum(vector<vector<int>>& matrix) {
        memset(dp, 1e9, sizeof dp);
        int n = matrix.size(), m = matrix[0].size();
        for(int i=0; i<m; i++) dp[0][i] = matrix[0][i];
        for(int i=0; i<m; i++) cout << dp[0][i] << endl;
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                dp[i][j] = 1e9;
                if(j-1>=0) dp[i][j] = min(dp[i][j],dp[i-1][j-1]);
                if(j+1<n) dp[i][j] = min(dp[i][j],dp[i-1][j+1]);
                dp[i][j] = min(dp[i][j],dp[i-1][j]);
                dp[i][j] += matrix[i][j];
            }
        }
        int ans = 1e9;
        for(int i=0; i<m; i++) ans = min(ans, dp[n-1][i]);
        return ans;
    }
};