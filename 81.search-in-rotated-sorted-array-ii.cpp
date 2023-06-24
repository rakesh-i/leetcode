/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0;
        int hi = n-1;
        while(lo<=hi){
            if(nums[lo]==target||nums[hi]==target){
                return true;
            }
            int mid = (lo+hi)/2;
            double num = (nums[mid]<nums[0])==(target<nums[0])?
                        nums[mid]:
                        (target<nums[0])?-INFINITY:INFINITY;
            if(nums[hi]==nums[lo]){
                else{
                    lo++;
                    hi--;
                }
            }
            else if(num<target){
                lo = mid+1;
            }
            else if(num>target){
                hi = mid-1;
            }
            else{
                return true;
            }

        }
        return false;

    }
};
// @lc code=end

