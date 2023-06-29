/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
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
            b[x][y] = '1';
            int i = x;
            int j = y-1;
            if(j>=0){
                if(b[x][j]=='O'){
                    a.push({x, j});
                    b[x][j] = '1';
                }
            }
            j = y+1;
            if(j<m){
                if(b[x][j]=='O'){
                    a.push({x, j});
                    b[x][j] = '1';
                }
            }
            j = y;
            i = x-1;
            if(i>=0){
                if(b[i][y]=='O'){
                    a.push({i, y});
                    b[i][y] = '1';
                }
            }
            i = x+1;
            if(i<n){
                if(b[i][y]=='O'){
                    a.push({i, y});
                    b[i][y] = '1';
                }
            }
            a.pop();
        }
    }

    void solve(vector<vector<char>>& b) {
        int n = b.size();
        int m = b[0].size();
        for(int i=0; i<m; i++){
            if(b[0][i]=='O'||b[0][i]=='1'){
                helper(b, 0, i, n, m);
            }
        }   
        for(int i=0; i<n; i++){
            if(b[i][0]=='O'||b[i][0]=='1'){
                helper(b, i, 0, n, m);
            }
        }   
        for(int i=0; i<m; i++){
            if(b[n-1][i]=='O'||b[n-1][i]=='1'){
                helper(b, n-1, i, n, m);
            }
        }   
        for(int i=0; i<n; i++){
            if(b[i][m-1]=='O'||b[i][m-1]=='1'){
                helper(b,i, m-1, n, m);
            }
        }   

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(b[i][j]=='O'){
                    b[i][j] = 'X';
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(b[i][j]=='1'){
                    b[i][j] = 'O';
                }
            }
        }
    }
};
// @lc code=end

