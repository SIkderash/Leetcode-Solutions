// https://leetcode.com/problems/maximize-number-of-subsequences-in-a-string

class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
       long long ans1 = 0, ans2 = 0;
        int n = text.size();
        long long p[n], q[n];
        char x = pattern[0], y = pattern[1];
        for(int i=0; i<n; i++) p[i]=0, q[i]=0;
        if(text[0]==x) p[0] = 1;
        if(text[0]==y) q[0] = 1;
        for(int i=1; i<n; i++){
            p[i] = p[i-1];
            q[i] = q[i-1];
            if(text[i]==x) p[i]++;
            if(text[i]==y) q[i]++;
            //cout << p[i] << " " << q[i] << endl;
        }

        for(int i=n-1; i>0; i--){
            if(text[i]==y){
                ans1+=p[i-1];
            }
        }
        ans1+=p[n-1];
        for(int i=0; i<n; i++){
            if(text[i]==x){
                ans2+=q[n-1]-q[i];
            }
        }

        ans2+=q[n-1];
        return max(ans1, ans2);
    }
};