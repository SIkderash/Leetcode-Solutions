// https://leetcode.com/problems/n-th-tribonacci-number

class Solution {
public:
    int tribonacci(int n) {
        vector<long long int>t;
        t.push_back(0);
        t.push_back(1);
        t.push_back(1);
        for(int i=3; i<=37; i++){
            t.push_back(t[i-1]+t[i-2]+t[i-3]);
        }
        return t[n];
    }
};