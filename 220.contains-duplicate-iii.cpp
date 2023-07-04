/*
 * @lc app=leetcode id=220 lang=cpp
 *
 * [220] Contains Duplicate III
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();
        for(int i=0; i<n-1; i++){
            for(int j=i+1;j<n&&j<=i+indexDiff;j++){
                if(abs(nums[i]-nums[j])<=valueDiff){
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end

