// https://leetcode.com/problems/total-appeal-of-a-string

class Solution {
public:
    long long appealSum(string s) {
        long long dp[100000+10], last[26];
        int n = s.size();
        for(int i=0; i<26; i++)  last[i] = -1;
        last[s[0]-'a'] = 0;
        dp[0] = 1;
        long long ans = 1;
        for(int i=1; i<n; i++){
            dp[i] = dp[i-1];
            dp[i] += (i-last[s[i]-'a']);
            last[s[i]-'a'] = i;
            ans += dp[i];
            //cout << ans << endl;
        }
        return ans;
    }
};