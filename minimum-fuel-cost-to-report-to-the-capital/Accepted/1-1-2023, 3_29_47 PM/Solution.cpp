// https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital

class Solution {
public:
    vector<int>adj[100000+5];
    bool vis[100000+5];
    long long n, k, fuel = 0;
    
    pair<long long, long long> dfs(int s, long long cars, long long seats){
        vis[s] = true;
        long long tempCars = cars;
        long long tempSeats = seats;
        for(auto x : adj[s]){
            if(!vis[x]){
                pair<long long,long long> temp = dfs(x, tempCars, tempSeats);
                //cout << x << " " << temp.first << endl;
                cars += temp.first;
                fuel += temp.first;
                seats += temp.second;
            }
        }
        long long needed = cars*k - seats;
        cars = (needed+k-1)/k;
        seats = cars*k - needed;
        //cout << s << " " << cars << endl;
        if(s!=0){
            if(seats>0) seats--;
            else{
                cars++;
                seats += k-1;
            }
        }
        return {cars, seats};
    }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        n = roads.size()+1;
        k = seats;
        for(auto x : roads){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        pair<int,int> p = dfs(0, 0, 0);
        return fuel;

    }
};