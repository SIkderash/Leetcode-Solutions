// https://leetcode.com/problems/minimum-jumps-to-reach-home

class Solution {
    public:
    int dp[6005][2];
    bool flag = false;

    int f(int cur, int a, int back, int b, int x, set<int> s){ 
        if(cur==x) {
            flag = true;
            return 0;
        }
        if(dp[cur][back]!=-1) {
            return dp[cur][back];
        }
        if(cur+a<=6000){
            if(!(s.count(cur+a))){
                dp[cur][back] = 1+f(cur+a,a,0,b,x,s);
            }
        }
        if(back==0 && cur-b>0){
            if(!(s.count(cur-b))){
                dp[cur][back] = min(dp[cur][back], 1+f(cur-b,a,1,b,x,s));
            }
        }
        return dp[cur][back];
    }
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        set<int> s;
        for(auto i: forbidden) s.insert(i);
        for(int i=0; i<=6000; i++){
            dp[i][0]=dp[i][1]=-1;
        }
        int ans = f(0,a,0,b,x,s);
        if(flag) return ans; 
        return -1;
    }
        
};