/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution {
public:
    int path(vector<vector<int>>& o, int m, int n,vector<vector<int>>&l){
        if(m>=0 && n>=0 && o[m][n]==1){
            return 0;
        }
        if(m<0||n<0){
            return 0;
        }
        if(m==0&&n==0){
            return 1;
        }
        if(l[m][n]!=-1){
            return l[m][n];
        }
        l[m][n] = path(o, m-1, n, l)+path(o, m, n-1, l);
        return l[m][n];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
        int m = Grid.size();
        int n = Grid[0].size();
        vector<vector<int>> l(m+1,vector<int> (n+1,-1));
        return path(Grid, m-1, n-1,l);
    }
};
// @lc code=end

