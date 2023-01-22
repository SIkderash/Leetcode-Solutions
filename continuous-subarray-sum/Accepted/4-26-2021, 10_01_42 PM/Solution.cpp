// https://leetcode.com/problems/continuous-subarray-sum

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int> v = nums;
        int n = nums.size();
        map<int,int>mp;
        int sum = v[0]%k;
        mp[sum] = 0;
        for(int i=1; i<v.size(); i++){
            int x = v[i];
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