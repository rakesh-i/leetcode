/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    void helper(int idx, int n, int sum, vector<int> temp,int k){
        if(sum==n){
            if(temp.size()==k){
                res.push_back(temp);
            }
            
            return;
        }
        for(int i=idx; i<=9; i++){
            sum+=i;
            temp.push_back(i);
            helper(i+1, n, sum, temp,k);
            sum-=i;
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        helper(1, n, 0, temp, k);
        return res;
    }
};
// @lc code=end

