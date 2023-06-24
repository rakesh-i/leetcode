/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int high = n-1;
        int low  = 0;
        while(low<=high){
            int mid= (low+high)/2;
            if(nums[mid]==target){
                int top = mid;
                int bot = mid;
                while(top<n&&nums[top]==target){
                    top++;
                }
                while(bot>-1&&nums[bot]==target){
                    bot--;
                }
                return {bot+1, top-1};
            }
            else if(nums[mid]<target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }

        }
        return {-1, -1};
    }
};
// @lc code=end

