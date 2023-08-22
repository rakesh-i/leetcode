/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution {
public:
    int l[101][101] = {0};
    int uniquePaths(int m, int n) {
        if(m==1||n==1){
            return 1;
        }
        if(l[m][n]!=0){
            return l[m][n];
        }
        l[m][n] = uniquePaths(m-1, n)+uniquePaths(m, n-1);
        return l[m][n];
    }
};
        
// @lc code=end

