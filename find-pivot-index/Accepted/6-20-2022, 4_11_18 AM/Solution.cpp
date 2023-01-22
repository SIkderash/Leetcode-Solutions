// https://leetcode.com/problems/find-pivot-index

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int pre[10005];
        pre[0] = nums[0];
        int n = nums.size();
        for(int i=1; i<n; i++){
            pre[i] = pre[i-1] + nums[i];
        }
        for(int i=0; i<n; i++){
            int left = (i==0)? 0 : pre[i-1];
            int right = (i==n-1)? 0 : pre[n-1]-pre[i];
            if(left==right) return i;
        }
        return -1;
    }
};