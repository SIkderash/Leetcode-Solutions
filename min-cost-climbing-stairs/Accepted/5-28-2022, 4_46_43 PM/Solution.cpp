// https://leetcode.com/problems/min-cost-climbing-stairs

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        long long int ans[n+5];
        for(int i=0; i<n+5; i++) ans[i] = 100000000;
        ans[0] = cost[0];
        ans[1] = cost[1];
        for(int i=2; i<n; i++){
            ans[i] = min(ans[i-1], ans[i-2]) + cost[i];
        }
        return min(ans[n-1], ans[n-2]);
    }
};