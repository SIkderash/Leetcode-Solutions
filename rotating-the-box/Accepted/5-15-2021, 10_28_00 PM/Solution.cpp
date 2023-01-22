// https://leetcode.com/problems/rotating-the-box

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size();
        int m = box[0].size();
          vector<string> v[n];

        vector<vector<char> > ans;
        for(int i=0; i<n; i++){
            string temp = "";
            for(int j=0; j<m; j++){
                temp+=box[i][j];
            }
            int dot = 0, hsh = 0;
            string t = "";
            for(int j=0; j<m; j++){
                if(temp[j]=='*'){
                    for(int k=0; k<dot; k++) t+=".";
                    for(int k=0; k<hsh; k++) t+="#";
                    t+="*";
                    dot = 0;
                    hsh = 0;
                }
                else{
                    if(temp[j]=='.') dot++;
                    else hsh++;
                }
            }
            for(int k=0; k<dot; k++) t+=".";
            for(int k=0; k<hsh; k++) t+="#";
            vector<char> ans1;
            for(auto c: t) ans1.push_back(c);
            ans.push_back(ans1);
        }
        vector<vector<char> > ans2;
        for(int j=0; j<m; j++){
            vector<char> ans3;
            for(int i=0; i<n; i++){
                ans3.push_back(ans[i][j]);
            }
            reverse(ans3.begin(), ans3.end());
            ans2.push_back(ans3);
        }
        return ans2;

        
    }
};