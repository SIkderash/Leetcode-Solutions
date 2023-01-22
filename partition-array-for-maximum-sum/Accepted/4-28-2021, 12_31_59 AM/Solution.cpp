// https://leetcode.com/problems/partition-array-for-maximum-sum

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>a;
        a.push_back(0);
        for(int i=1; i<=arr.size(); i++) a.push_back(arr[i-1]);
        int n = arr.size();
        int dp[n+1];
        dp[0] = 0;
        dp[1] = a[1];
        
        for(int i=2; i<=n; i++){
            int ans = 0, maxi = a[i];
            for(int j=1; j<=k && i-j>=0; j++){
                int l = i-j;
                maxi = max(maxi, a[l+1]);
                ans = max(ans, dp[l]+maxi*j);
            }
            dp[i] = ans;
        }
        return dp[n];
    }
};