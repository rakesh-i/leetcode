/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
class Solution {
public:
    void helper(vector<vector<string>> &res, vector<string> &cur, int r, int n,
                                 vector<int> &c, vector<int> &pd, vector<int> &nd){
        if(r==n){
            res.push_back(cur);
            return;             
        }
        for(int i=0; i<n; i++){
            if(c[i]&&pd[i+r]&&nd[n-1+i-r]){
                c[i]=pd[i+r]=nd[n-1+i-r]=0;
                cur[r][i] = 'Q';
                helper(res, cur, r+1, n, c,pd,nd);
                c[i]=pd[i+r]=nd[n-1+i-r]=1;
                cur[r][i] = '.';
            }
            
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<int> c(n,1), pd(2*n-1,1),nd(2*n-1,1);
        vector<string> cur;
        string x = "";
        for(int j=0; j<n; j++){
            x = x+'.';
        }
        for(int i = 0; i<n; i++){
            cur.push_back(x);
        }
        vector<vector<string>> res;
        helper(res, cur, 0, n, c,pd,nd);
        return res;
    }
};
// @lc code=end

