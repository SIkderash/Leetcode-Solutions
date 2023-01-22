// https://leetcode.com/problems/sum-of-prefix-scores-of-strings

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        map<string, int>mp;
        vector<string>v;
        for(int j=0; j<words.size(); j++){
                string x = words[j];
                string temp = "";
                for(int i=0; i<x.size(); i++){
                    temp += x[i];
                    mp[temp]++;
                }
        }
        vector<int>v1;
        for(int j=0; j<words.size(); j++){
                int ans = 0;
                string x = words[j];
                string temp = "";
                for(int i=0; i<x.size(); i++){
                    temp += x[i];
                    ans += mp[temp];
                }
                v1.push_back(ans);
        }
        return v1;
        
    }
};