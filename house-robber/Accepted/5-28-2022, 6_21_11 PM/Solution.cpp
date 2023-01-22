// https://leetcode.com/problems/house-robber

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int ans[n];
        ans[0] = nums[0];
        ans[1] = nums[1];
        for(int i=2; i<n; i++){
            ans[i] = ans[i-2];
            if(i-3>=0) ans[i] = max(ans[i], ans[i-3]);
            ans[i] += nums[i];
        }
        return max(ans[n-1], ans[n-2]);
    }
};