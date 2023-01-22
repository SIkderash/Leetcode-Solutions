// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0, j=0, n=nums.size();
        while(i<n && j<n){
            nums[i]=nums[j];
            while(j<n && nums[i]==nums[j]) j++;
            i++;
        }
        return i;
    }
};