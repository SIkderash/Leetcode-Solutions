// https://leetcode.com/problems/continuous-subarray-sum

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int>mp;
        int sum = nums[0]%k;
        mp[sum] = 0;
        for(int i=1; i<nums.size(); i++){
            int x = nums[i];
            sum = (sum+x)%k;
            if(sum==0) {
                return true;
            }
            if(mp.count(sum)){
                int j = mp[sum];
                if(i-j>=2){
                    return true;
                }
            }
            else{
                mp[sum] = i;
            }
        }
        return false;
    }
};