/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int count = 1;
        cout<<count<<endl;
        vector<vector<int>> a(n, vector<int> (n));
        int l = 0  , r = n-1, t = 0, b = n-1;
        while(l<=r&&t<=b){
            for(int i=l; i<=r; i++){
                a[t][i] = count++;
            }
            t++;
            for(int i=t; i<=b; i++){
                a[i][r] = count++;
            }
            r--;
            if(t<=b){
                for(int i=r; i>=l; i--){
                    a[b][i] =count++;
                }
                b--;
            }
            if(l<=r){
                for(int i=b; i>=t; i--){
                    a[i][l]  =  count++;
                }
                l++;
            }
        }
        return a;  
    }
};
// @lc code=end

