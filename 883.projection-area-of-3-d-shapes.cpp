/*
 * @lc app=leetcode id=883 lang=cpp
 *
 * [883] Projection Area of 3D Shapes
 */

// @lc code=start
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int x = 0;
        int xm = 0;
        int t = 0;
        int n = grid.size();
        vector<int> a(n,0);
        
        for(int i=0; i<n; i++){
            x = 0;
            for(int j=0; j<n; j++){
                if(grid[i][j]){
                    t++;
                }
                x = max(x, grid[i][j]);
                a[j] = max(grid[i][j],  a[j]);
            }
            xm = xm+x;
        }
        int y =0;
        for(int i=0; i<n; i++){
            y = y+ a[i];
        }
        return y+t+xm;
    }
};
// @lc code=end

