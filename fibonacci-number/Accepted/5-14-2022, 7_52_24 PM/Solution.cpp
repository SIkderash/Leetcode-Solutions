// https://leetcode.com/problems/fibonacci-number

class Solution {
public:
    int fib(int n) {
        vector<long long int>f;
        f.push_back(0);
        f.push_back(1);
        for(int i=2; i<=30; i++){
            f.push_back(f[i-1]+f[i-2]);
        }
        return f[n];
    }
};