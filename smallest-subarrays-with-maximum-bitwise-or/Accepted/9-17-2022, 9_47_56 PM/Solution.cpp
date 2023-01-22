// https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& a) {
        vector<int>b[32];
        int n = a.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<32; j++){
                if(a[i]&(1<<j)) {
                   b[j].push_back(i);
                }
            }
        }
        
        for(int i=0; i<32; i++){
            sort(b[i].begin(), b[i].end());
        }
        
        vector<int> an;
        for(int i=0; i<n; i++){
            int ans = i;
            //cout << i<< endl;
            for(int j=0; j<32; j++){
                if((a[i]&(1<<j)) == 0 and b[j].size()>0){
                    //cout << j << " ";
                    
                        int ind = lower_bound(b[j].begin(), b[j].end(), i) - b[j].begin();
                        
                        if(ind>=b[j].size()) continue;
                        
                        else{
                            //cout << ind << " " << b[j][ind] << endl;
                            ans = max(ans, b[j][ind]);
                        }
                    
                }
            }
            an.push_back(ans-i+1);
            
        }
        
        return an;
    }
};