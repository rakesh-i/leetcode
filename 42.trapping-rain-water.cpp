/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftmax(n), rightmax(n);
        int lm=0;
        int rm=0;
        for(int i=0; i<n; i++){
            lm = max(lm, height[i]);
            leftmax[i] = lm;
        }
        for(int i=n-1; i>=0; i--){
            rm = max(rm, height[i]);
            rightmax[i] = rm;
        }
        int sum = 0;
        for(int i=0;i<n; i++){
            sum+=min(rightmax[i], leftmax[i])-height[i];
        }
        return sum;
    }
};
// @lc code=end

