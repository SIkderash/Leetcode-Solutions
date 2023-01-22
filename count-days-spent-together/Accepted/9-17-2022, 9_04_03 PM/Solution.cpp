// https://leetcode.com/problems/count-days-spent-together

class Solution {
public:
    int countDaysTogether(string a, string b, string c, string d) {
        
        int ar[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for(int i=1; i<=12; i++) ar[i]+=ar[i-1];
        
        int l1 = stoi(a.substr(0, 2));
        int r1 = stoi(b.substr(0, 2));
        int l2 = stoi(c.substr(0, 2));
        int r2 = stoi(d.substr(0, 2));
        
        l1 = ar[l1-1] + stoi(a.substr(3, 2));
        r1 = ar[r1-1] + stoi(b.substr(3, 2));
        
        
        l2 = ar[l2-1] + stoi(c.substr(3, 2));
        r2 = ar[r2-1] + stoi(d.substr(3, 2));
        
        if(l1>l2){
            swap(l1, l2);
            swap(r1, r2);
        }
        
        if(r1<l2){
            return 0;
        }
        else{ 
            int l = l2;
            int r = min(r2, r1);
            return r-l+1;
        }
        
    }
};