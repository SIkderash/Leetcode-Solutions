// https://leetcode.com/problems/minimize-the-maximum-of-two-arrays

class Solution {
public:
    #define ll long long 
    ll minimizeSet(ll d1, ll d2, ll c1, ll c2) {
        if(d1>d2){
            swap(c1, c2);
            swap(d1, d2);
        }
        ll ans = 0;
        ans = d1*(c1/(d1-1))-1;
        if(c1%(d1-1)!=0) {
            ans++;
            ans += c1%(d1-1);
        }
       // cout << ans << endl;
        ll lm = lcm(d2, d1);
        c2 -= ans/lm;
        //cout << c2 << endl;
        if(c2<0) return ans;
        if(ans%d2!=0){
            ll temp = d2*((ans/d2)+1);
            //cout << temp << endl;
            c2 -= (temp - ans);
            ans = temp;
        }
        //cout << c2 << endl;
        ll temp = d2*(c2/(d2-1))-1;
        ans += temp;
        if(c2%(d2-1)!=0) {
            ans++;
            ans += c2%((d2-1));
        }
        return ans;
    }
};