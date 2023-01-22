// https://leetcode.com/problems/minimum-white-tiles-after-covering-with-carpets

class Solution {
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int i=0, j=0, n = floor.size();
        int totWhite = 0;
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q;
        for(int i=0; i<n; i++){
            int j = i, cnt = 0;
            if(floor[i]=='1'){
                while(i<n && floor[i]=='1'){
                    cnt++;
                    i++;
                }
                totWhite += cnt;
                q.push({j, cnt});
            }
        }
        //cout << totWhite << endl;
        i = 0;
        while(i<numCarpets && q.size()>0){
             pair<int, int> cur = q.top();
             q.pop();
            //cout << cur.first << " " << cur.second << endl;
            if(cur.second>carpetLen){
                int j = cur.first;
                int cnt = cur.second - carpetLen;
                q.push({j,cnt});
            }
            totWhite -= min(cur.second, carpetLen);
            i++;
        }
        return totWhite;
    }
};