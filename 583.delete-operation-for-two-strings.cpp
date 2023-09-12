/*
 * @lc app=leetcode id=583 lang=cpp
 *
 * [583] Delete Operation for Two Strings
 */

// @lc code=start
class Solution {
public:
    int dp[501][501];
    int helper(string &w1, string &w2, int m, int n){
        if(m==0||n==0){
            return 0;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        if(w1[m-1]==w2[n-1]){
            return dp[m][n] = 1+helper(w1, w2, m-1, n-1);
        }
        else{
            return dp[m][n]=max(helper(w1, w2, m-1, n), helper(w1, w2, m, n-1));
        }
        
    }
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof(dp));
        int m = word1.length(), n = word2.length();
        int x = helper(word1, word2, word1.size(), word2.size());
        return (m-x)+(n-x);
    }
};
// @lc code=end

