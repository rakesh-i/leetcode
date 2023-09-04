/*
 * @lc app=leetcode id=1277 lang=cpp
 *
 * [1277] Count Square Submatrices with All Ones
 */

// @lc code=start
class Solution {
public:
    int dp[301][301];
    int helper(int n, int m, vector<vector<int>>&mat, int i, int j){
        if(i>=m||j>=n||mat[i][j]==0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int temp = 1+min(helper(n, m, mat, i+1, j), min(helper(n, m, mat, i, j+1), helper(n, m, mat, i+1, j+1)));
        return dp[i][j] = temp;
    }
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int count = 0;
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]==1){
                    count+=helper(n, m, matrix, i, j);
                }
            }
        }
        return count;
    }
};
// @lc code=end

