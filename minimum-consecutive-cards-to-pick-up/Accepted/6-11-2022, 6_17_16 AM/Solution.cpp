// https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int vis[1000000+5];
        for(int i=0; i<=1000000; i++) vis[i] = -1;
        int ans = 1000001;
        for(int i=0; i<cards.size(); i++){
            if(vis[cards[i]]>=0){
                ans = min(ans, i-vis[cards[i]]+1);
            }
            vis[cards[i]] = i;
        }
        if(ans==1000001) return -1;
        return ans;
    }
};