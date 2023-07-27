/*
 * @lc app=leetcode id=18 lang=csharp
 *
 * [18] 4Sum
 */

// @lc code=start
public class Solution {
    public IList<IList<int>> FourSum(int[] nums, int target) {
        IList<IList<int>> res = new List<IList<int>>();
        int n = nums.Length;
        Array.Sort(nums);
        for(int i=0; i<n-3; i++){
            for(int j=i+1; j<n-2; j++){
                int k = j+1;
                int l = n-1;
                while(k<l){
                    long ans = (long)nums[i]+(long)nums[j]+(long)nums[k]+(long)nums[l];
                    if(ans==(long)target){
                        IList<int> a = new List<int> (){nums[i],nums[j], nums[k], nums[l]};
                        int flag = 0;
                        foreach(List<int> x in res){
                            if(Enumerable.SequenceEqual(a, x)==true){
                                flag = 1;
                            }
                        }
                        if(flag==0){
                            res.Add(a);
                        }
                        k++;
                        l--;
                    }
                    else if(ans<(long)target){
                        k++;
                    }
                    else{
                        l--;
                    }
                }
            }
        }   
        return res;
    }
}
// @lc code=end

