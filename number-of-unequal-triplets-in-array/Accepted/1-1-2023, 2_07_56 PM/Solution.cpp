// https://leetcode.com/problems/number-of-unequal-triplets-in-array

class Solution {
public:
    int unequalTriplets(vector<int>& a) {
        int n = a.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k = j+1; k<n; k++){
                    if(a[i]!=a[j] and a[j]!=a[k] and a[k]!=a[i]){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};