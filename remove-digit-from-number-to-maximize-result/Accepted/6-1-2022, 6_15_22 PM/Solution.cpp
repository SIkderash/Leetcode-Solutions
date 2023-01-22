// https://leetcode.com/problems/remove-digit-from-number-to-maximize-result

class Solution {
public:
    string removeDigit(string number, char digit) {
        int pos = 0;
        for(int i=0; i<number.size(); i++){
            if(number[i]==digit) pos = i;
            if(i+1 < number.size() && number[i]==digit && number[i+1]>digit){
                string ans = number.substr(0,i) + number.substr(i+1,number.size()-(i+1));
                return ans;
            }
        }
        return number.substr(0,pos) + number.substr(pos+1, number.size()-(pos+1));
    }
};