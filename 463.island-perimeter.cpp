/*
 * @lc app=leetcode id=463 lang=cpp
 *
 * [463] Island Perimeter
 */

// @lc code=start
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        for(int i=0; i<n;i++){
            for(int j=0; j<m;j++){
                if(grid[i][j]==1){
                    int a = (i-1<0)?0:(grid[i-1][j]==1)?1:0;
                    int b = (i+1>n-1)?0:(grid[i+1][j]==1)?1:0;
                    int c = (j-1<0)?0:(grid[i][j-1]==1)?1:0;
                    int d = (j+1>m-1)?0:(grid[i][j+1]==1)?1:0;
                    res = res+4-(a+b+c+d);
                }
            }
        }
        return res;
    }
};
// @lc code=end

