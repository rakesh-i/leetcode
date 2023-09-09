/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
class Solution { 
public:
    int dp[10001];
    int helper(int n, int c){
        if(n==0){;
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int ans = INT_MAX;
        for(int i=sqrt(n); i>0; i--){
            ans = min(1+helper(n-i*i, c+1), ans);
            
        }
        return dp[n]= ans;
        
    }
    int numSquares(int n) {
        memset(dp, -1, sizeof(dp));
         return helper(n, 0);
        //  return mn;
    }
};
// @lc code=end

