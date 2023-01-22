// https://leetcode.com/problems/pascals-triangle

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > ans;
        vector<int> temp;
        temp.push_back(1);
        ans.push_back(temp);
        for(int i=2; i<=numRows; i++){
            vector<int> a;
            for(int j=0; j<i; j++){
               
                if(j==0) a.push_back(1);
                else if(j==i-1) a.push_back(1);
                else {
                    a.push_back(temp[j-1]+temp[j]);
                }
            }
            ans.push_back(a);
            temp = a;
        }
        return ans;
    }
};