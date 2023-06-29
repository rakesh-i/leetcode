/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
public:
    void helper(vector<vector<char>>& b, int e, int f, int n, int m){
        queue<pair<int, int>> a;
        a.push({e, f});
        while(!a.empty()){
            int x = a.front().first;
            int y = a.front().second;
            b[x][y] = '0';
            int i = x;
            int j = y-1;
            if(j>=0){
                if(b[x][j]=='1'){
                    a.push({x, j});
                    b[x][j] = '0';
                }
            }
            j = y+1;
            if(j<m){
                if(b[x][j]=='1'){
                    a.push({x, j});
                    b[x][j] = '0';
                }
            }
            j = y;
            i = x-1;
            if(i>=0){
                if(b[i][y]=='1'){
                    a.push({i, y});
                    b[i][y] = '0';
                }
            }
            i = x+1;
            if(i<n){
                if(b[i][y]=='1'){
                    a.push({i, y});
                    b[i][y] = '0';
                }
            }
            a.pop();
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1'){
                    count++;
                    helper(grid, i, j, n, m);
                }
            }
        }
        return count;

    }
};
// @lc code=end

