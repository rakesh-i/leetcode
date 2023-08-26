/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    void helper(int num, vector<int> temp, int idx, int n, int k){
        if(temp.size()==k){
            res.push_back(temp);
            return;
        }
        for(int j=idx; j<n; j++){
            temp.push_back(j+1);
            helper(j+1, temp, j+1, n, k);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        // vector<int>num;
        // for(int i=0; i<n; i++){
        //     num.push_back(i+1);
        // }
        int num = 1;
        vector<int> temp;
        helper(num, temp, 0, n, k);
        return res;
    }
};
// @lc code=end

