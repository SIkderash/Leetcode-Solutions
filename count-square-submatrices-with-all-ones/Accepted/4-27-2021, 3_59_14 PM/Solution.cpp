// https://leetcode.com/problems/count-square-submatrices-with-all-ones

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> a = matrix;
        int pre[n][m];
        memset(pre,0,sizeof pre);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(j-1>=0) pre[i][j] = pre[i][j-1];
                pre[i][j]+=a[i][j];
            }
        }
        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=i; j<m; j++){
                int l = j-i+1;
                int temp = 0;
                for(int k=0; k<n; k++){
                    if(k+l-1>=n) break;
                    if(k==0){
                        for(int c=k; c<=k+l-1; c++){
                            temp += pre[c][j];
                            if(i-1>=0) temp -= pre[c][i-1];
                        }
                    }
                    else{
                        int toDelete = pre[k-1][j];
                        if(i-1>=0) toDelete -= pre[k-1][i-1];
                        temp -= toDelete;
                        int toAdd = pre[k+l-1][j];
                        if(i-1>=0) toAdd -= pre[k+l-1][i-1];
                        temp += toAdd;
                    }
                    if(temp==l*l) ans++;
                }
            }
        }
        return ans;
    }
};