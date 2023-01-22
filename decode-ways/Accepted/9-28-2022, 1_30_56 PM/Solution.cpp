// https://leetcode.com/problems/decode-ways

class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0') return 0;
        int n = s.size();
        vector<long long int>v(n+1, 0);
        v[0] = 1;
        for(int i=1; i<=n; i++){
            int lastDigitCanForm = s[i-1]-'0';
            if(lastDigitCanForm>=1 && lastDigitCanForm<=26) v[i] = v[i-1];
            if(i>1 and s[i-2]!='0'){
                int lastTwoDigitCanForm = s[i-2]-'0';
                lastTwoDigitCanForm *= 10;
                lastTwoDigitCanForm += s[i-1]-'0';
                if(lastTwoDigitCanForm>=1 and lastTwoDigitCanForm<=26) v[i] += v[i-2];
            }
        }
        return v[n];
    }
};

