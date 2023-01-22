// https://leetcode.com/problems/remove-digit-from-number-to-maximize-result

class Solution {
public:
    string removeDigit(string number, char digit) {
        string temp = number;
        int n = temp.size();
        string ans;
        for(int i=0; i<temp.size()-1; i++){
            if(temp[i]==digit && temp[i]<temp[i+1]){
                string ans = temp.substr(0,i) + temp.substr(i+1, n-i-1);
                return ans;
            }
        }
        for(int i=temp.size()-1; i>=0; i--){
            if(temp[i]==digit){
                ans = temp.substr(0,i) + temp.substr(i+1, n-i-1);
                break;
            }
        }
        return ans;
    }
};