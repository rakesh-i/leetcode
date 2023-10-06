/*
 * @lc app=leetcode id=1387 lang=cpp
 *
 * [1387] Sort Integers by The Power Value
 */

// @lc code=start
class Solution {
public:
    int dp[1000000];
    int helper(int x){
        if(x==1){
            return 0;
        }
        if(dp[x]!=-1){
            return dp[x];
        }
        int count = 0;
        if(x%2==0){
            count = 1+helper(x/2);
        }
        else{
            count = 1+helper(x*3+1);
        }
        return dp[x] = count;
    }
    int getKth(int lo, int hi, int k) {
        memset(dp, -1, sizeof(dp));
        vector<pair<int, int>> res;
        for(int i=lo; i<=hi; i++){
            res.push_back({helper(i),i});
        }
        sort(res.begin(), res.end());

        return res[k-1].second;
    }
};
// @lc code=end

