/*
 * @lc app=leetcode id=885 lang=cpp
 *
 * [885] Spiral Matrix III
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result;
        int total = 0;

        int rowStart = rStart;
        int rowEnd = rStart;

        int colStart = cStart;
        int colEnd = cStart;

        while(true){
            for(int i=colStart; i<=colEnd; i++){
                if(i >= 0 && i < cols && rowStart >= 0){
                    result.push_back({rowStart, i});
                    total++;
                }
            }
            colEnd++;
            if(total == (rows * cols))
                break;
            for(int i=rowStart; i<=rowEnd; i++){
                if(i >= 0 && i < rows && colEnd < cols){
                    result.push_back({i, colEnd});
                    total++;
                }
            }
            rowEnd++;
            if(total == (rows * cols))
                break;
            for(int i=colEnd; i>=colStart; i--){
                if(i >= 0 && i < cols && rowEnd < rows){
                    result.push_back({rowEnd, i});
                    total++;
                }
            }
            colStart--;
            if(total == (rows * cols))
                break;
            for(int i=rowEnd; i>=rowStart; i--){
                if(i >= 0 && i < rows && colStart >= 0){
                    result.push_back({i, colStart});
                    total++;
                }
            }
            rowStart--;
            if(total == (rows * cols))
                break;
        }
        return result;
    }
};
// @lc code=end

