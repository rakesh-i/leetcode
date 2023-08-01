/*
 * @lc app=leetcode id=55 lang=csharp
 *
 * [55] Jump Game
 */

// @lc code=start
public class Solution {
    public bool CanJump(int[] nums) {
        int sum = 0;
        int n = nums.Length;
        for(int i=0; i<n; i++){
            sum = Math.Max(sum, i+nums[i]);
            if(sum>=n-1){
                return true;
            }
            if(sum==i&&nums[i]==0){
                return false;
            }
        }
        return true;
    }
}
// @lc code=end

