// https://leetcode.com/problems/k-concatenation-maximum-sum

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long int sum = 0, maxsum=0, mod = 1e9+7;
        int n = arr.size();
        for(int i=0; i<n; i++){
            sum+=arr[i];
            if(sum<0) sum=0;
            maxsum = max(sum, maxsum);
        }
        long long int pre = 0, temp1 = 0;
        for(int i=0; i<n; i++){
            temp1 += arr[i];
            pre = max(pre, temp1);
            
        }
        long long int suf = 0, temp2 = 0;
        for(int i=n-1; i>=0; i--){
            temp2 += arr[i];
            suf = max(suf, temp2);
        }
        
        long long ans1 = maxsum;
        long long ans2 = (k>=2)*(pre+suf);
        if((k>=3)*(k-2)*temp1>0) ans2 += (k>=3)*(k-2)*temp1;
        long long int ans = max(ans1, ans2);
        return ans%mod;
    }
};