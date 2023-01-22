// https://leetcode.com/problems/count-square-submatrices-with-all-ones

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        bool dp[305][305][305] = {0};
        int n = matrix.size(), m = matrix[0].size();
        
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                dp[i][j][1] = matrix[i][j];
                if(dp[i][j][1]) cnt++;
            }
        }
        for(int l=2; l<=min(n,m); l++){
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    int k = i+l-1;
                    int o = j+l-1;
                    if(k<n && o<m){
                        dp[i][j][l] = dp[i][j][l-1] && dp[i][j+1][l-1]
                                    && dp[i+1][j][l-1] && dp[i+1][j+1][l-1];
                        if(dp[i][j][l]) cnt++;
                    }
                }
            }
        }
        return cnt;
        
    }
};