// https://leetcode.com/problems/largest-rectangle-in-histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        int n = a.size();
        vector<int>ls(n,-1);
        vector<int>rs(n,n);
        stack<int>s;
        for(int i=0; i<n; i++){
            while(!s.empty() and a[s.top()]>a[i]){
                rs[s.top()] = i;
                s.pop();
            }
            if(!s.empty()){
                if(a[s.top()]==a[i]) ls[i] = ls[s.top()];
                else ls[i] = s.top();
            }
            s.push(i);
        }
        int ans = -1;
        for(int i=0; i<n; i++){
            int l = ls[i]>=0? ls[i]+1 : 0;
            int r = rs[i]<n? rs[i]-1 : n-1;
            ans = max(ans, a[i]*(r-l+1));
        }
        return ans;
    }
};