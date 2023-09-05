/*
 * @lc app=leetcode id=1043 lang=cpp
 *
 * [1043] Partition Array for Maximum Sum
 */

// @lc code=start
class Solution {
public:
    int dp[510];
    int helper(int i, int k, vector<int> &arr){
        if(i==arr.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int mx = 0;
        int ans = 0;
        for(int j=i; j<i+k&&j<arr.size(); j++){
            mx=max(mx, arr[j]);
            ans = max(ans,mx*(j-i+1)+helper(j+1, k, arr));
        }
        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp, -1, sizeof(dp));
        return helper(0, k, arr);
    }
};
// @lc code=end

