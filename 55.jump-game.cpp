/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0]=1;
        for(int i=0; i<n; i++){
            if(dp[i]==1){
                if(i+nums[i]==n-1){
                    return true;
                }
                for(int j=i; j<n&&j<=i+nums[i]; j++){
                    dp[j] = 1;
                }
            }
        }
        //cout<<"df"<<endl;
        return dp[n-1];
    }
};
// @lc code=end

