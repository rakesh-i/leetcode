/*
 * @lc app=leetcode id=454 lang=cpp
 *
 * [454] 4Sum II
 */

// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int res = 0;
        unordered_map<int, int> m;
        for(auto &it1 :nums1){
            for(auto &it2:nums2){
                m[it1+it2]++;
            }
        }
        for(auto &it3:nums3){
            for(auto &it4:nums4){
                if(m[0-it3-it4]){
                    res += m[0-it3-it4];
                }
            }
        }
        return res;
    }
};
// @lc code=end

