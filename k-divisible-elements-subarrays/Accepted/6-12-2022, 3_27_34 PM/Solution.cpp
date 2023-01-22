// https://leetcode.com/problems/k-divisible-elements-subarrays

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();
        set<string>ans;
        for(int i=0; i<n; i++){
            string s = "";
            int cnt = 0;
            for(int j=i; j<n; j++){
                if(nums[j]%p==0) cnt++;
                if(cnt > k) break;
                s += to_string(nums[j])+" ";
                ans.insert(s);
            }
        }
        //for(auto x: ans) cout << x << endl;
        return ans.size();
    }
};