/*
 * @lc app=leetcode id=11 lang=csharp
 *
 * [11] Container With Most Water
 */

// @lc code=start
public class Solution {
    public int MaxArea(int[] height) {
        int n = height.Length;
        int i = 0;
        int j = n-1;
        int l = 0;
        while(i<j){
            int h = (Math.Min(height[i], height[j]));
            int w = j-i;
            int area = h*w;
            l = Math.Max(area, l);
            if(height[i]>height[j]){
                j--;
            }
            else{
                i++;
            }
        }
        return l;
        
    }
}
// @lc code=end

