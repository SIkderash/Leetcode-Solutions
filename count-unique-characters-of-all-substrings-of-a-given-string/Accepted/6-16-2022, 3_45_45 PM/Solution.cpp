// https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string

class Solution {
public:
    int uniqueLetterString(string s) {
        long long dp[100000+10], last[26][2];
        int n = s.size();
        for(int i=0; i<26; i++)  last[i][0] = last[i][1] = -1;
        last[s[0]-'A'][0] = 0;
        dp[0] = 1;
        long long ans = 1;
        for(int i=1; i<n; i++){
            dp[i] = dp[i-1];
            dp[i] += (i-last[s[i]-'A'][0]);
            dp[i] -= (last[s[i]-'A'][0]-last[s[i]-'A'][1]);
            if(last[s[i]-'A'][0]==-1){
                last[s[i]-'A'][0] = i;
            }
            else {
                last[s[i]-'A'][1] = last[s[i]-'A'][0];
                last[s[i]-'A'][0] = i;
            }
            ans += dp[i];
            //cout << dp[i] << endl;
        }
        return ans;
    }
};