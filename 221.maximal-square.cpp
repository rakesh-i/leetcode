/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

// @lc code=start
class Solution {
public:
    int dp[301][301];
    int helper(vector<vector<char>>&mat, int i, int j, int m, int n){
        if(i>=m||j>=n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(mat[i][j]=='1'){
            int a = helper(mat, i+1, j, m, n);
            int b = helper(mat, i, j+1, m, n);
            int c = helper(mat, i+1, j+1, m, n);
            int ans = 1+min(a, min(b,c));
            return dp[i][j] = ans;
        }
        return 0;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        memset(dp, -1, sizeof(dp));
        int mx = 0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0; j<matrix[i].size();j++){
               mx = max(helper(matrix, i, j, matrix.size(), matrix[0].size()),mx);
            }
        }
        return mx*mx;
    }
};
// @lc code=end

