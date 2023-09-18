/*
 * @lc app=leetcode id=132 lang=cpp
 *
 * [132] Palindrome Partitioning II
 */

// @lc code=start
class Solution {
public:
    int dp[2001][2001]={0};
    int memo[2001];
    int res = INT_MAX;
    int helper(int n, int idx){
        if(idx>=n||dp[idx][n-1]){  
            return 0;
        }
        if(memo[idx]!=-1){
            return memo[idx];
        }
        int ans = 0;
        int temp = INT_MAX;
        for(int i=idx; i<n; i++){
            if(dp[idx][i]==1){
                ans = 1+helper(n, i+1);
                temp = min(ans, temp);
            }
        }
        return memo[idx] = temp;
    }

    int minCut(string s) {
        int n = s.size();
        memset(memo, -1, sizeof(memo));
        for(int j=0; j<n; j++){
            for(int i=0; i<=j; i++){
                if(s[i]==s[j]&&(j-i<=2||dp[i+1][j-1]==1)){
                    dp[i][j]=1;
                }
            }
        }
        return helper(n, 0);
    }
};
// @lc code=end

