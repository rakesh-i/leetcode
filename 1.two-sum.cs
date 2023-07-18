/*
 * @lc app=leetcode id=1 lang=csharp
 *
 * [1] Two Sum
 */

// @lc code=start
public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        Hashtable m = new Hashtable();
        int n = nums.Length;
        int[] res = new int[2];
        for(int i=0; i<n; i++){
            if(m.ContainsKey(target-nums[i])){
                res[0] = i;
                res[1] =(int) m[target-nums[i]];
                return res;
            }
            
            m[nums[i]]=i;
        }
        return res;
    }
}
// @lc code=end

