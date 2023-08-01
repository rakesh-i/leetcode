/*
 * @lc app=leetcode id=47 lang=csharp
 *
 * [47] Permutations II
 */

// @lc code=start
public class Solution {
    public void helper(int[] nums, int i, int n, IList<IList<int>> res){
        if(i==n){
            IList<int> temp = new List<int>(nums);
            int flag = 0;
            foreach(List<int> x in res){
                if(Enumerable.SequenceEqual(temp, x)==true){
                    flag = 1;
                }
            }
            if(flag == 0){
                res.Add(temp);
            }
            return;
        }
        for(int k = i; k<n; k++){
            Swap(nums, i, k);
            helper(nums, i+1, n, res);
            Swap(nums, i, k);
        }
    }
    private void Swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    public IList<IList<int>> PermuteUnique(int[] nums) {
        //Array.Sort(nums);
        IList<IList<int>> res = new List<IList<int>>();
        helper(nums, 0, nums.Length,  res);
        return res;
    }
}
// @lc code=end

