/*
 * @lc app=leetcode id=324 lang=cpp
 *
 * [324] Wiggle Sort II
 */

// @lc code=start
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> a(nums);
        int j = 0;
        sort(a.begin(), a.end());
        for(int i=nums.size()-1; i>=0; i--){
            if(i%2==0){
                nums[i] = a[j++];
            }
        }
        for(int i=nums.size()-1; i>=0; i--){
            if(i%2){
                nums[i] = a[j++];
            }
        }

    }
};
// @lc code=end

