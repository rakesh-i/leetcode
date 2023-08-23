/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
public:
    void helper(int i, vector<vector<int>> &l, vector<int>&c, vector<int> temp, int n, int sum, int target){
        if(i==n){
            if(sum==target){
                l.push_back(temp);   
            }
            return;
        }
        if(sum+c[i]<=target){
            sum +=c[i];
            temp.push_back(c[i]);
            helper(i,l, c, temp, n, sum, target);
            sum -=c[i];
            temp.pop_back(); 
        }
        helper(i+1, l, c, temp, n, sum, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> l;
        vector<int> t;
        helper(0, l, candidates, t, candidates.size(), 0, target);
        return l;
    }
};
// @lc code=end

