/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start
class Solution {
public:
    int characterReplacement(string s, int k) {
        int lo = 0;
        int hi = s.size();
        unordered_map<char, int> m;
        int maxi =0;
        int cur = 0;
        int ans = 0;
        while(cur<hi){
            maxi = max(++m[s[cur]], maxi);
            if((cur-lo+1-maxi)>k){
                m[s[lo]]--;
                lo++;
            }
            ans = max(ans, (cur-lo+1));
            cur++;
        }
        return ans;
    }
};
// @lc code=end

