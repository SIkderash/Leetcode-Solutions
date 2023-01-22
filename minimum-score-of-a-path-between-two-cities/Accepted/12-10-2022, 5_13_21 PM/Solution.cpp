// https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities

class Solution {
    #define pb push_back     
public:
    int ans = 100000;
    bool vis[100000+5];
    
    void dfs(int s, vector<pair<int,int> >g[]){
        vis[s] = true;
        for(auto p : g[s]){
            ans = min(ans, p.second);
            if(!vis[p.first] )dfs(p.first, g);
        }
    }
    int minScore(int n, vector<vector<int>>& r) {
    
        vector<pair<int,int> >g[n+1];
        for(auto x : r){
            g[x[0]].pb({x[1], x[2]});
            g[x[1]].pb({x[0], x[2]});
        }
        dfs(1, g);
        return ans;
    }
};