// https://leetcode.com/problems/count-substrings-that-differ-by-one-character

class Solution {
public:
    bool dp[105][105][105][2];
    int countSubstrings(string s, string t) {
        int n = s.size();
        int m = t.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(s[i]!=t[j]) {
                    cnt++;
                    dp[i][j][1][1] = true;
                }
                else{
                    dp[i][j][1][0] = true;
                }
            }
        }
        
        for(int l=2; l<=min(n,m); l++){
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    int x = i+l-1;
                    int y = j+l-1;
                    //cout << i << " " << j << " " << l << endl;
                    if(x<n && y<m){
                        if(s[x]==t[y]) {
                            dp[i][j][l][0] = dp[i][j][l-1][0];
                            dp[i][j][l][1] = dp[i][j][l-1][1];
                        }
                        else {
                            dp[i][j][l][1] = dp[i][j][l-1][0];
                        }
                        if(dp[i][j][l][1]) {
                            cnt++;
                        }
                    }
                }
            }
        }
        return cnt;
        
    }
};