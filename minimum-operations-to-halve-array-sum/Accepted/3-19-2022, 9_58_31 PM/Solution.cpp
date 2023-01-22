// https://leetcode.com/problems/minimum-operations-to-halve-array-sum

class Solution {
public:
    int halveArray(vector<int>& nums) {
    priority_queue<long double> s;
        long double sum = 0;
        for(auto x: nums){
            s.push(x);
            sum+=x;
        }
        long double temp = sum/2;
        int cnt = 0;
        while(temp>0){
            cnt++;
            long double now = s.top();
            temp-=now/2;
            if(temp<0) break;
            s.pop();
            s.push(now/2);
        }
        //cout << cnt << endl;
        return cnt;
    }
};