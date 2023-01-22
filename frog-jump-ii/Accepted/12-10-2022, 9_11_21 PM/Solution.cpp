// https://leetcode.com/problems/frog-jump-ii

class Solution {
public:
    int maxJump(vector<int>& a) {
        int ans = -1;
        int n = a.size();
        int i =0, g = 0;
        while(i<n-1){
            int j = i+2;
            if(j>=n) {
                j--;
                g = 1;
            }
            ans = max(ans, abs(a[j]-a[i]));
            i = j;
        }
        reverse(a.begin(), a.end());
        i = 0;
        while(i<n-1){
            int j = i+2;
            if(i==0){
                if(g==0) j = i+1;
            }
            if(j>=n) j = n-1;
            ans = max(ans, abs(a[j]-a[i]));
            i = j;
        }
        return ans;
    }
};