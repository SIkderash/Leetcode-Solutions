// https://leetcode.com/problems/divide-players-into-teams-of-equal-skill

class Solution {
    #define ll long long 
public:
    long long dividePlayers(vector<int>& a) {
        int n = a.size();
        map<int, int>mp;
        ll sum = 0;
        for(auto x: a) {sum+= x; mp[x]++;}
        if((sum*2)%n!=0){
            return -1;
        }
        ll temp = (sum*2)/n, ans = 0;
        for(auto x : a){
            if(mp[x]>0){
                mp[x]--;
                ll y = temp-x;
                if(mp[y]>0){
                    mp[y]--;
                    ans+= x*y;
                }
                else{
                    return -1;
                }
            }
        }
        return ans;
    }
};