/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0;
        int hi = n-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            double num = (nums[mid]<nums[0])==(target<nums[0])?nums[mid]:
                        (target<nums[0])?-INFINITY:INFINITY;
            if(num<target){
                lo = mid+1;
            }
            else if(num>target){
                hi = mid-1;
            }
            else{
                return mid;
            }
            
        }
        return -1;
    }
};
// @lc code=end

