// https://leetcode.com/problems/sorting-the-sentence

class Solution {
public:
    string sortSentence(string s) {
        int i = 0;
        int n = s.size();
        vector<pair<int,string> > v;
        istringstream iss(s);
        string word;
        while(iss >> word) {
            string temp = word.substr(0,word.size()-1);
            int k = word[word.size()-1]-'0';
            v.push_back({k,temp});
        }
        sort(v.begin(), v.end());
        string ans = "";
        for(int i=0; i<v.size(); i++){
            ans += v[i].second;
            if(i!=v.size()-1) ans+= " "; 
        }
        return ans;
    }
};