// https://leetcode.com/problems/incremental-memory-leak

class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        int now = 1;
        int t = 1;
        while(now<=memory1 || now <=memory2){
            t++;
            if(memory1>=memory2){
                memory1-=now;
            }
            else{
                memory2-=now;
            }
            now++;
        }
        vector<int> ans;
        ans.push_back(t);
        ans.push_back(memory1);
        ans.push_back(memory2);
        return ans;
    }
};