// https://leetcode.com/problems/maximum-value-of-a-string-in-an-array

class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int ans = -1;
        for(auto s : strs){
            int n = s.size();
            int f = 0;
            int val = 0;
            for(auto c : s){
                if(!(c>='0' and c<='9')){
                    f = 1;
                    break;
                }
            }
            if(f==1){
                ans = max(ans, n);
            }
            else{
                ans = max(ans, stoi(s));
            }
        }
        return ans;
    }
};