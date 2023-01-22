// https://leetcode.com/problems/length-of-the-longest-alphabetical-continuous-substring

class Solution {
public:
    int longestContinuousSubstring(string s) {
        int l = 0;
        int ans = 1 , cnt = 1;
        for(int i=1; i<s.size(); i++){
            int cur = s[i]-'a';
            int p = s[i-1]-'a';
            if(cur==p+1){
                cnt++;
                ans = max(ans, cnt);
            }
            else{
                cnt = 1;
            }
        }
        return ans;
    }
};