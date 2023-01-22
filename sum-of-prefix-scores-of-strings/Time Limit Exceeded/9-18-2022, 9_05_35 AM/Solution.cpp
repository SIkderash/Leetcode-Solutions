// https://leetcode.com/problems/sum-of-prefix-scores-of-strings

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        map<string, int>mp;
        int n = words.size();
        vector<string>v[n];
        for(int j=0; j<words.size(); j++){
                string x = words[j];
                string temp = "";
                for(int i=0; i<x.size(); i++){
                    temp += x[i];
                    mp[temp]++;
                    v[j].push_back(temp);
                }
        }
        vector<int>v1;
        for(int j=0; j<words.size(); j++){
                int ans = 0;
                for(int i=0; i<v[j].size(); i++){
                    //string x = v[j][i];
                    ans += mp[v[j][i]];
                }
                v1.push_back(ans);
        }
        return v1;
        
    }
};