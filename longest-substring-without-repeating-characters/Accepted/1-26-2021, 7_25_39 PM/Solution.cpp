// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
     int lengthOfLongestSubstring(string s) {
        int ans = 0;
        map<char,bool> vis;

        int i=0, j=0, n=s.length();
        
        while(i<n && j<n){
            if(vis[s[j]]==false) { vis[s[j]] = true; j++; ans = max(ans, j-i);}
            else{
                vis[s[i]]=false;
                i++;
            }
        }
        return ans;

    }
};