// https://leetcode.com/problems/categorize-box-according-to-criteria

class Solution {
public:
    string categorizeBox(int a, int b, int c, int d) {
        int bl = 0, h =0;
        long long x = 1;
        x*=a;
        x*=b;
        x*=c;
        if(a>=10000 || b>=10000 || c>=10000 || d>=10000 || x>=1000000000){
            bl = 1;
        }
        if(d>=100) h = 1;
        if(bl and h) return "Both";
        else if(bl) return "Bulky";
        else if(h) return "Heavy";
        return "Neither";
    }
};