// https://leetcode.com/problems/count-sorted-vowel-strings


class Solution {
public:
    int countVowelStrings(int n) {
        long long dp[51+1][6];
        for(int i=0; i<51; i++){
            for(int j=0; j<6; j++){
                dp[i][j] = 0;
            }
        }
        for(int i=1; i<6; i++){
            dp[1][i] = 1;  
        }
        for(int i=2; i<n+1; i++){
            for(int j=1; j<6; j++){
                for(int k = 1; k<=j; k++){
                    dp[i][j] += dp[i-1][k];
                }
                //cout << dp[i][j] << " ";
            }
            //cout << endl;
        }
        long long int sum = 0;
        for(int i=1; i<6; i++){
            sum += (long long) dp[n][i];
        }
        return sum;
    }
};