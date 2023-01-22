// https://leetcode.com/problems/minimum-cost-tree-from-leaf-values

class Solution {
public:
    pair<int,int> dp[50][50];
    pair<int,int> f(int start, int fin, vector<int>a , int n){
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
    }
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        for(int i=0; i<50; i++) 
            for(int j=0; j<50; j++)
                dp[i][j].first = -1;
        return f(0,n-1,arr,n).second;
    }
};