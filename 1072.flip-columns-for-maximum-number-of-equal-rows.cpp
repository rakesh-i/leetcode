/*
 * @lc app=leetcode id=1072 lang=cpp
 *
 * [1072] Flip Columns For Maximum Number of Equal Rows
 */

// @lc code=start
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& m) {
        unordered_map<string, int> n;
        for(auto &r:m){
            string s(r.size(), 'T');
            for(int i=1; i<r.size(); i++){
                s[i] = (r[i]!=r[0])?'F':'T';
            }
            n[s]++;
        }
        int  ans = 0;
        for(auto i:n){
            ans = max(ans, i.second);
        }
        return ans;
    }
};
// @lc code=end

