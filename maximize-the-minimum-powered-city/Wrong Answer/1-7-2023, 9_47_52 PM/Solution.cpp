// https://leetcode.com/problems/maximize-the-minimum-powered-city

class Solution {
public:
    #define ll long long
    ll l[100000+5];
    ll r[100000+5];
    
    int f(int mid, int n){
        ll sum = 0;
        for(int i=0; i<n; i++){
            if(l[i]<mid) sum += mid-l[i];
        }
        return sum;
    }
    
    long long maxPower(vector<int>& a, int ra, int k) {
        int n = a.size();
        l[0] = a[0];
        r[n-1] = a[n-1];
        for(int i=1; i<n; i++){
            l[i] = a[i];
            l[i] += l[i-1];
            //cout << l[i] << " ";
            if(i-ra-1>=0) l[i] -= a[i-ra-1];
            //cout << l[i] << endl;
        }
        
        //cout << endl;
        
        for(int i=n-2; i>=0; i--){
            r[i] = a[i];
            r[i] += r[i+1];
            //cout << r[i] << " ";
            if(i+ra+1<n) r[i] -= a[i+ra+1];            
            //cout << r[i] << endl;
        }
        
        //cout << endl;
        
        ll maxi = -1;
        for(int i=0; i<n; i++){
            l[i] += r[i];
            l[i] -= a[i];
            maxi = max(maxi, l[i]);
        }
        int lo = 0, hi = k+maxi;
        while(hi-lo>=5){
            int mid = (lo+hi)/2;
            if(f(mid, n)<=k) lo = mid;
            else hi = mid-1;
        }
        
        ll ans = lo;
        for(int i=hi; i>=lo; i--){
            if(f(i, n)<=k) return i;
        }
        return ans;
    }
};