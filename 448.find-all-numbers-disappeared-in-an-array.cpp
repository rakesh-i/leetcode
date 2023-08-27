/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 */

// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        int n = nums.size();
        for(int i=1; i<=n; i++){
            if(!binary_search(nums.begin(), nums.end(), i)){
                res.push_back(i);
            }
        }
        return res;

    }
};
// @lc code=end

