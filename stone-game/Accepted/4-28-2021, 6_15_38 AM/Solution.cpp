// https://leetcode.com/problems/stone-game

class Solution {
public:
    int dp[505][505];
    int csum[505];
    int get(int start, int fin){
        int ans = csum[fin];
        if(start>0) ans -= csum[start-1];
        return ans;
    }
    int f(int start, int fin, vector<int> a){
        if(start==fin) return a[start];
        if(dp[start][fin]!=0) return dp[start][fin];
        int ans1 = a[start]+ get(start+1,fin)-f(start+1,fin,a);
        int ans2 = a[fin]+ get(start,fin-1)-f(start,fin-1,a);
        dp[start][fin] = max(ans1,ans2);
        return dp[start][fin];
    }
    bool stoneGame(vector<int>& piles) {
        csum[0] = piles[0];
        int n = piles.size();
        for(int i=1; i<n; i++) csum[i] = csum[i-1]+piles[i];
        for(int i=0; i<n; i++){
            dp[i][i] = piles[i];
        }
        for(int l=2; l<=n; l++){
            for(int i=0; i<n; i++){
                int j= i+l-1;
                if(j>=n) break;
                dp[i][j] = max(piles[i]+get(i,j)-dp[i+1][j], piles[j]+get(i,j)-dp[i][j-1]);
            }
        }
        return dp[0][n-1]>get(0,n-1)-dp[0][n-1];
    }
};