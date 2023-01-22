// https://leetcode.com/problems/maximum-star-sum-of-a-graph

class Solution {
    #define pb push_back
    #define ll long long 
public:
    int maxStarSum(vector<int>& a, vector<vector<int>>& e, int k) {
        int n = a.size();
        vector<int>g[n];
        for(auto x : e){
            g[x[0]].pb(a[x[1]]);
            g[x[1]].pb(a[x[0]]);
        }
        for(int i=0; i<n; i++){
            for(auto x : g[i]){
                cout << x << " ";
            }
            cout << endl;
        }
        ll ans = -100000;
        for(int i=0; i<n; i++){
            ll temp = a[i];
            sort(g[i].rbegin(), g[i].rend());
            int j = 0;
            for(auto x : g[i]){
                if(x<0) break;
                else temp += x;
                j++;
                if(j>=k) break;
            }
            if(temp > ans){
                ans = temp;
                cout << i << " " << temp << endl;
            }
        }
        return ans;
    }
};