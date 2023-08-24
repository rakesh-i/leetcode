/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 */

// @lc code=start
class Solution {
public:
    int count = 0;
    void helper(vector<int> &c, int i, int t, int sum, int n){
        if(sum==t){
            count++;
            return;
        }
        if(sum>t){
            return;
        }
        for(int j=i; j<n; j++){
            sum+=c[j];
            helper(c, i+1, t, sum, n);
            sum-=c[j];
        }
        helper(c, i+1, t, sum, n);
    }
    int combinationSum4(vector<int>& nums, int target) {
        helper(nums, 0, target, 0, nums.size());
        return count;
    }
};
// @lc code=end

