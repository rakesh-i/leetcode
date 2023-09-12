/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
class Solution {
public:
    int dp[501][501];
    int helper(string &w1, string &w2, int m, int n){
        if(m==0){
            return dp[m][n] = n;
        }
        if(n==0){
            return dp[m][n] = m;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        if(w1[m-1]==w2[n-1]){
            return dp[m][n] = helper(w1, w2, m-1, n-1); 
        }
        else{
            int insert = helper(w1, w2, m, n-1);
            int del = helper(w1, w2, m-1, n);
            int replace = helper(w1, w2, m-1, n-1);
            return dp[m][n] = 1+min({insert, del, replace});
        }
    }
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof(dp));
        return helper(word1, word2, word1.size(), word2.size());
    }
};
// @lc code=end

