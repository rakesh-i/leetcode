/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int> &c, vector<int> temp, int i, int t, int k, int sum){
        if(temp.size()==k&&sum==t){
            res.push_back(temp);
            return;
        }
        if(temp.size()>k){
            return;
        }
        for(int j=i; j<9; j++){
            sum+=c[j];
            temp.push_back(c[j]);
            helper(c, temp, j+1, t, k, sum);
            sum-=c[j];
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> c = {1,2,3,4,5,6,7,8,9};
        vector<int> temp;
        helper(c, temp, 0, n, k, 0);
        return res;
    }
};
// @lc code=end

