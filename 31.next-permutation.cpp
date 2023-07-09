/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i,l;
        int n = nums.size();
        for(i=n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                break;
            }
        }
        if(i<0){
            reverse(nums.begin(), nums.end());
        }
        else{
            for(l=n-1; l>i; l--){
                if(nums[l]>nums[i]){
                    break;
                }
            }
            swap(nums[i], nums[l]);
            reverse(nums.begin()+i+1, nums.end());
        }
    }
};
// @lc code=end

