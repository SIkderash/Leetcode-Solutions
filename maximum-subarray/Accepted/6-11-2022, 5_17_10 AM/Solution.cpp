// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = -10000000000;
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            if(sum+nums[i]>=0) {
                sum +=nums[i];
                ans = max(ans, sum);
            }
            else {
                sum = 0;
            }
        }
        ans = max(ans, sum);
        if(ans==0){
            return *max_element(nums.begin(), nums.end());
        }
        return ans;
    }
};