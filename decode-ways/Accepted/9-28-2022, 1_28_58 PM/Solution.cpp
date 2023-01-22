// https://leetcode.com/problems/decode-ways

class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0') return 0;
        int n = s.size();
        vector<long long int>v(n+1, 0);
        v[0] = 1;
        for(int i=1; i<=n; i++){
            int x = s[i-1]-'0';
            //cout <<"x" <<  " " << x << endl;
            if(x>=1 && x<=26) v[i] = v[i-1];
            if(i>1 and s[i-2]!='0'){
                int temp = s[i-2]-'0';
                temp *= 10;
                temp += s[i-1]-'0';
                //cout <<"2x" <<  " " << temp << endl;
                if(temp>=1 and temp<=26) v[i] += v[i-2];
            }
            //cout << "vi" << v[i] << endl;
        }
        return v[n];
    }
};

