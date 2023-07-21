/*
 * @lc app=leetcode id=26 lang=csharp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
public class Solution {
    public int RemoveDuplicates(int[] nums) {
        int[] a = nums;
        int n = nums.Length;
        int k = 0;
        for(int i=0; i<n; i++){
            int x=a[i];
            int cur = i;
            nums[k] = a[i];
            while(i<n&&a[i]==x){
                i++;
            }
            k++;
            i--;
        }
        return k;

    }
}
// @lc code=end

