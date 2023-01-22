// https://leetcode.com/problems/divide-array-into-equal-pairs

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        set<int>s;
        multiset<int>ml;
        for(auto x : nums) s.insert(x);
        for(auto x : nums) ml.insert(x);
        for(auto x: s){
            if(ml.count(x)%2!=0){
                return false;
            }
        }
        return true;
    }
};