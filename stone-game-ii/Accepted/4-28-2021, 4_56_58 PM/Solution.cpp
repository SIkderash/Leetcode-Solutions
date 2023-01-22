// https://leetcode.com/problems/stone-game-ii

class Solution {
public:
    int dp[105][105];
    int csum[105];
    int get(int start, int fin){
        if(start>fin) return 0;
        int ans = csum[fin];
        if(start>0) ans -= csum[start-1];
        return ans;
    }
    int f(int start, int fin, vector<int> a, int m){
        if(start>fin) return 0;
        if(start == fin) {
            dp[start][m] = a[start];
            return dp[start][m];
        }
        if(dp[start][m]!=0) return dp[start][m];
        for(int i=1; i<=2*m && start+i-1<=fin; i++){
            int ans1 = get(start,start+i-1) + get(start+i,fin)-f(start+i,fin,a,max(i,m));
            dp[start][m] = max(dp[start][m],ans1);
        }    
        int ans = dp[start][m];
        return ans;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        csum[0] = piles[0];
        for(int i=1; i<n; i++) csum[i] = csum[i-1]+piles[i];
        int ans = f(0,n-1,piles,1);
        return ans;
    }
};