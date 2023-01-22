// https://leetcode.com/problems/matrix-block-sum

class Solution {
public:
    int solve(vector<int> v){
        int temp =0;
        for(int i=0; i<v.size(); i++){
            temp+=v[i];       
        }
        return temp;
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n= mat.size(), m = mat[0].size(); 
        int pre[n][m];
        memset(pre, 0, sizeof pre);
        vector<vector<int>>ans(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i-1>=0) pre[i][j]+=pre[i-1][j];
                if(j-1>=0) pre[i][j]+=pre[i][j-1];
                if(i-1>=0 && j-1>=0) pre[i][j]-=pre[i-1][j-1];
                pre[i][j]+=mat[i][j];
                //cout << pre[i][j] << " " << endl;
            }
        }
        for(int i=0; i<n; i++){
            ans[i].resize(m);
            for(int j=0; j<m; j++){
                int r2 = min(n-1,i+k);
                int r1 = i-k;
                int c2 = min(m-1,j+k);
                int c1 = j-k;
                int temp = pre[r2][c2];
                if(r1>0) temp-= pre[r1-1][c2];
                if(c1>0) temp-= pre[r2][c1-1];
                if(r1>0 && c1>0) temp+= pre[r1-1][c1-1];
                ans[i][j] = temp;
            }
        }
        return ans;
    }
};