/*
 * @lc app=leetcode id=45 lang=csharp
 *
 * [45] Jump Game II
 */

// @lc code=start
public class Solution {
    public int Jump(int[] nums) {
        int n = nums.Length;
        int sum = 0;
        int cur = 0;
        int jump = 0;
        for(int i=0; i<n-1; i++){
            sum = Math.Max(sum, i+nums[i]);
            if(i==cur){
                jump++;
                cur = sum;
            }
        }
        return jump;
    }
}
// @lc code=end

