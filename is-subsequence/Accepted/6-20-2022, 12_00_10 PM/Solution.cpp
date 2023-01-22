// https://leetcode.com/problems/is-subsequence

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0, j=0;
        if(s.size()==0) return true;
        if(t.size()==0) return false;
        while(i<s.size()){
            if(s[i]==t[j]){
                i++;  j++;
            }
            else{
                j++;
            }
            if(i!= s.size() && j==t.size()) return false;
        }
        return true;
    }
};