/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int min = 50001;
        while(low<high){
            if(nums[low]<nums[high]){
                return nums[low];
            }
            int mid = (low+high)/2;
            if(nums[mid]>=nums[low]){
                low = mid+1;
            }
            else{
                high = mid;
            }
            
        }
        return nums[low];
    }
};
// @lc code=end

