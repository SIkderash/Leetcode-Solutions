// https://leetcode.com/problems/count-prefixes-of-a-given-string

class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int count = 0;
        for(int i=0; i<words.size(); i++){
            int now = words[i].size();
            bool is = true;
            if(now>s.size()) continue;
            for(int j=0; j<now; j++){
                if(words[i][j]!=s[j]){
                    is = false;
                    break;
                }
            }
            if(is){
                count++;
                cout << words[i] << endl;
            }
        }
        return count;
    }
};