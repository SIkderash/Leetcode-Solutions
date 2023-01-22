// https://leetcode.com/problems/minimum-average-difference

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        vector<long long int>sum;
        int n = nums.size();
        sum.push_back(nums[0]);
        for(int i=1; i<nums.size(); i++){
            sum.push_back(sum[i-1]+nums[i]);
        }
        long long tot = sum[n-1];
        long long mini = 10000000000;
        int ans = 0;
        for(int i=0; i<sum.size(); i++){
            //cout << i << endl;
            long long diff = 0;
            if(i!=n-1) diff = sum[i]/(i+1) - (tot - sum[i])/(n-i-1);
            else diff = sum[i]/(i+1);
            diff = abs(diff);
            //cout << diff << endl;
            if(diff<mini){
                ans = i;
                mini = diff;
            }
        }
        return ans;
    }
};