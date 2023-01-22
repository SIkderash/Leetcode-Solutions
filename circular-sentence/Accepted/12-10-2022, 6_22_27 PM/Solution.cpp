// https://leetcode.com/problems/circular-sentence

class Solution {
public:
    bool isCircularSentence(string str) {
        istringstream ss(str);
        vector<string>v;
        string temp;
        while(ss >> temp){
            v.push_back(temp);
        }
        if(v.size()==1){
            return v[0][v[0].size()-1]==v[0][0];
        }
        for(int i=1; i<v.size(); i++){
            string s1 = v[i];
            string s2 = v[i-1];
            char c1 = s1[0];
            char c2 = s2[s2.size()-1];
            if(c1!=c2) return false;
        }
        return v[v.size()-1][v[v.size()-1].size()-1] == v[0][0];
    }
};