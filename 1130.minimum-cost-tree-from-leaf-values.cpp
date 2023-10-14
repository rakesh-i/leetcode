/*
 * @lc app=leetcode id=1130 lang=cpp
 *
 * [1130] Minimum Cost Tree From Leaf Values
 */

// @lc code=start
class Solution {
public:
    int dp[41][41];
    int max_val(vector<int>&arr, int s, int e){
        int mx = 0;
        for(int i=s; i<=e; i++){
            mx = max(mx, arr[i]);
        }
        return mx;
    }
    int helper(vector<int>&arr, int s, int e){
        if(s==e){
            return 0;
        }
        if(dp[s][e]!=-1){
            return dp[s][e];
        }
        int mn = INT_MAX;
        for(int i=s; i<e; i++){
            int left = max_val(arr, s, i);
            int right = max_val(arr, i+1, e);
            mn = min(mn, left*right+helper(arr, s, i)+helper(arr,i+1, e));
        }
        return dp[s][e] = mn;
    }

    int mctFromLeafValues(vector<int>& arr) {
        memset(dp, -1, sizeof(dp));
        return helper(arr, 0, arr.size()-1);
    }
};
// @lc code=end

