// https://leetcode.com/problems/maximum-enemy-forts-that-can-be-captured

class Solution {
public:
    #define pb push_back
    int captureForts(vector<int>& a) {
        int n = a.size();
        int o = -1;
        int e = -1;
        int ans = 0;
        for(int i=0; i<n; i++){
            if(a[i]==-1){
                if(o!=-1){
                    ans = max(abs(i-o)-1, ans); 
                    //cout << i << " " << o << endl;
                    o = -1;
                }
            }
            else if(a[i]==1) o = i;
        }
        reverse(a.begin(), a.end());
        o = -1;
        for(int i=0; i<n; i++){
            if(a[i]==-1){
                if(o!=-1){
                    ans = max(abs(i-o)-1, ans);
                    //cout << i << " " << o << endl;
                    o = -1;
                }
            }
            else if(a[i]==1) o = i;
        }
        return ans;
    }
};