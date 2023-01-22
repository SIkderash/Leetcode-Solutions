// https://leetcode.com/problems/minimum-cost-tree-from-leaf-values

class Solution {
public:
    pair<int,int> dp[50][50];
    /*pair<int,int> f(int start, int fin, vector<int>a , int n){
        if(start==fin){
            return {a[start],0};
        }
        if(dp[start][fin].first!=-1){
            return dp[start][fin];
        }
        int sum = 1e9, subMax = -1;
        for(int i=start; i<fin; i++){
            pair<int,int> left = f(start, i, a, n);
            pair<int,int> right = f(i+1, fin, a, n);
            sum = min(sum, left.second+ right.second + left.first*right.first);
            subMax = max(subMax, max(left.first, right.first));
        }
        return dp[start][fin] = {subMax,sum};
    }*/
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j){
                    dp[i][j].first = arr[i];
                    dp[i][j].second = 0;    
                }
                else{
                    dp[i][j].first = -1;
                    dp[i][j].second = 1e9;
                }
            }
        }
        
        for(int l=2; l<=n; l++){
            for(int i=0; i<n; i++){
                int j = i+l-1;
                if(j>=n) break;
                for(int k=i; k<j; k++){
                    dp[i][j].second = min(dp[i][j].second,dp[i][k].second+
                                          dp[k+1][j].second+dp[i][k].first*dp[k+1][j].first); 
                    dp[i][j].first = max(dp[i][j].first,
                                         max(dp[i][k].first,dp[k+1][j].first));
                }
            }
        }
        return dp[0][n-1].second;
    }
};