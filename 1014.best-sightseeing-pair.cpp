/*
 * @lc app=leetcode id=1014 lang=cpp
 *
 * [1014] Best Sightseeing Pair
 */

// @lc code=start
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int res = 0, cur = 0;
        for (int a: A) {
            res = max(res, cur + a);
            cur = max(cur, a) - 1;
        }
        return res;
    }
};
// @lc code=end

