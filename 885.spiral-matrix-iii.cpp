/*
 * @lc app=leetcode id=885 lang=cpp
 *
 * [885] Spiral Matrix III
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int c = 0;
        int rs = rStart;
        int re = rStart;

        int cs = cStart;
        int ce = cStart;
        vector<vector<int>> res;
        int n = rows*cols;
        while(true){
            for(int i=cs; i<=ce; i++){
                if(i>=0 && i<cols&& rs>=0){
                    res.push_back({rs, i});
                    c++;
                }
            }
            ce++;
            if(c==n){
                break;
            }
            for(int i=rs; i<=re; i++){
                if(i>=0 && i<rows&& ce<cols){
                    res.push_back({i,ce});
                    c++;
                }
            }
            re++;
            if(c==n){
                break;
            }
            for(int i=ce; i>=cs; i--){
                if(i>=0 && i<cols&& re<rows){
                    res.push_back({re,i});
                    c++;
                }
            }
            cs--;
            if(c==n){
                break;
            }
            for(int i=re; i>=rs; i--){
                if(i>=0 && i<rows&& cs>=0){
                    res.push_back({i,cs});
                    c++;
                }
            }
            rs--;
            if(c==n){
                break;
            }


        }
        return res;
    }
};
// @lc code=end

