/*
 * @lc app=leetcode id=396 lang=cpp
 *
 * [396] Rotate Function
 */

// @lc code=start
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        int cur = 0;
        for(int i=0; i<n; i++){
            total += nums[i];
            cur +=nums[i]*i;
        }
        int mx = cur;
        for(int i=n-1; i>=1; i--){
            cur = cur -nums[i]*(n-1)+total-nums[i];
            mx = max(cur, mx);
        }
        return mx;
    }
};
// @lc code=end

