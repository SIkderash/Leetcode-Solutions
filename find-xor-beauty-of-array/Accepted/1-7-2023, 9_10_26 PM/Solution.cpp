// https://leetcode.com/problems/find-xor-beauty-of-array

class Solution {
public:
    int xorBeauty(vector<int>& a) {
        int n = a.size();
        int ans = 0;
        for(int i=0; i<n; i++) ans = (ans^a[i]);
        return ans;
    }
};