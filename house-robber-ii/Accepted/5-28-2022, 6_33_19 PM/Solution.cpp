// https://leetcode.com/problems/house-robber-ii

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int ans[n];
        ans[0] = nums[0];
        ans[1] = nums[1];
        for(int i=2; i<n-1; i++){
            ans[i] = ans[i-2];
            if(i-3>=0) ans[i] = max(ans[i], ans[i-3]);
            ans[i] += nums[i];
        }
        int ans1[n];
        ans1[0] = 0;
        ans1[1] = nums[1];
        
        for(int i=2; i<n; i++){
            ans1[i] = ans1[i-2];
            if(i-3>=0) ans1[i] = max(ans1[i], ans1[i-3]);
            ans1[i] += nums[i];
        }
        int final_ans = max(ans1[n-1], ans[n-2]);
        if(n-3>=0) final_ans = max(final_ans, ans[n-3]);
        return final_ans;
    }
};