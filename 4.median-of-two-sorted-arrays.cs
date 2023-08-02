/*
 * @lc app=leetcode id=4 lang=csharp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
public class Solution {
    public double FindMedianSortedArrays(int[] nums1, int[] nums2) {
        List<int> a = new List<int>();
        int n = nums1.Length;
        int m = nums2.Length;
        int i=0, j=0;
        while(i<n&&j<m){
            if(nums1[i]>nums2[j]){
                a.Add(nums2[j]);
                j++;
            }
            else{
                a.Add(nums1[i]);
                i++;
            }
        }
        while(i<n){
            a.Add(nums1[i]);
            i++;
        }
        while(j<m){
            a.Add(nums2[j]);
            j++;
        }
        if((n+m)%2==0){
            int y = (n+m)/2;
            return ((double)a[y]+(double)a[y-1])/2.0;
        }
        else{
            int y = (n+m)/2;
            return (double)a[y];
        }
        return 0.0;
    }
}
// @lc code=end

