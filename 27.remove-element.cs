/*
 * @lc app=leetcode id=27 lang=csharp
 *
 * [27] Remove Element
 */

// @lc code=start
public class Solution {
    public int RemoveElement(int[] nums, int val) {
        int n = nums.Length;
        int[] a = nums;
        int k = 0;
        for(int i=0; i<n; i++){
            if(a[i]==val){
                continue;
            }
            else{
                nums[k]  = a[i];
                k++;
            } 
        }
        return k;
    }
}
// @lc code=end

