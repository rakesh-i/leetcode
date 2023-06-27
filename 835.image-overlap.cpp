/*
 * @lc app=leetcode id=835 lang=cpp
 *
 * [835] Image Overlap
 */

// @lc code=start
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int, int>> m1, m2;
        int n = img1.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(img1[i][j]==1){
                    m1.push_back({i, j});
                }
                if(img2[i][j]==1){
                    m2.push_back({i, j});
                }
            }
        }
        int ans = 0;
        map<pair<int, int>, int> x;
        for(auto i:m1){
            for(auto j:m2){
                int a = i.first - j.first;
                int b = i.second - j.second;
                x[{a, b}]++;
                ans = max(ans, x[{a,b}]);
            }
        }
        return ans;
    }
};
// @lc code=end

