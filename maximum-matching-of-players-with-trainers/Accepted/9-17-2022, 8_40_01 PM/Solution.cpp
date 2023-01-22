// https://leetcode.com/problems/maximum-matching-of-players-with-trainers

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& v) {
        /*set<int>s;
        for(auto x : trainers){
            s.insert(x);
        }
        */
        sort(players.begin(), players.end());
        sort(v.begin(), v.end());
        int n = v.size();
        int prev = 0;
        int ans = 0;
        for(auto x: players){
            int ind = lower_bound(v.begin()+prev, v.end(), x)-v.begin();
            if(ind>=n){
                break;
            }
            else{
                prev = ind+1;
                ans++;
            }
        }
        return ans;
    }
};