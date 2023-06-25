/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int right = 0;
        int  left = 0;
        int n = nums.size();
        int m = 100001;
        int cur = 0;

        for(int i=0; i<n; i++){
            cur += nums[i];
            while(cur>=target){
                m = min(m, i-left+1);
                cur -= nums[left];
                left++;
            }
        }
        return m==100001?0:m;
        
    }
};
// @lc code=end

