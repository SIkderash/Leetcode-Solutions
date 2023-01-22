// https://leetcode.com/problems/minimum-cost-for-tickets

class Solution {
public:
    int dp[400][400];
    int d[400];
    int p[400];
    void dijkstra(int s, int n) {
        
        vector<bool> u(n, false);
        d[s] = 0;
        p[s] = -1;
        for (int i = 1; i < n; i++) {
            int v = -1;
            for (int j = 1; j < n; j++) {
                if (!u[j] && (v == -1 || d[j] < d[v]))
                    v = j;
            }

            if (d[v] == 1000000000)
                break;

            u[v] = true;
            for (int to=1; to<n ; to++) {
                int len = dp[v][to];
                if (d[v] + len < d[to]) {
                    d[to] = d[v] + len;
                    p[to] = v;
                }
            }
        }
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int m = days.size();
        int n = days[m-1];
        for(int i=1; i<400; i++){
            d[i] = 1000000000;
            for(int j=1; j<400; j++){
                if(j==i+1 || i==j+1) {
                    dp[i][j] = 0;
                    dp[j][i] = 0;
                }
                else {
                    dp[i][j] = 1000000000;
                    dp[j][i] = 1000000000;
                }
            }
        }
        for(int j=0; j<m; j++){
            int i = days[j];
            dp[i][i+1] = min(costs[0],min(costs[1],costs[2]));
            dp[i][i+7] = min(costs[1],costs[2]);
            dp[i][i+30] = costs[2];
            dp[i+1][i] = min(costs[0],min(costs[1],costs[2]));
            dp[i+7][i] = min(costs[1],costs[2]);
            dp[i+30][i] = costs[2];
        }
        
        dijkstra(days[0], 400);
        return d[n+1];
    }
};