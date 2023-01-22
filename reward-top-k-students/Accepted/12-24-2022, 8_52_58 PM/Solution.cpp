// https://leetcode.com/problems/reward-top-k-students

class Solution {
public:
    vector<int> topStudents(vector<string>& ps, vector<string>& ng, vector<string>& re, vector<int>& id, int k) {
        vector<pair<int,int>>v;
        map<string,int>mp;
        int n = re.size();
        for(auto x : ps){
            mp[x] = 3;
        }
        for(auto x : ng){
            mp[x] = -1;
        }
        for(int i=0; i<n; i++){
            string str = re[i];
            stringstream s(str);
            string temp;
            int sc = 0;
            while(s >> temp){
                if(mp[temp]){
                    sc += mp[temp];
                }
            }
            v.push_back({sc, -id[i]});
        }
        sort(v.rbegin(), v.rend());
        vector<int> ans;
        for(int i=0; i<k; i++){
            ans.push_back(-v[i].second);
        }
        return ans;
    }
};