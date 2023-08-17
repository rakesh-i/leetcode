/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        vector<int> res;
        vector<vector<int>> a;
        for(auto i:m){
            a.push_back({i.second, i.first});
        }
        sort(a.begin(), a.end());
        int n = a.size();
        for(int i=n-1; i>=n-k; i--){
            res.push_back(a[i][1]);
        }
        return res;
    }
};
// @lc code=end

