/*
 * @lc app=leetcode id=1356 lang=cpp
 *
 * [1356] Sort Integers by The Number of 1 Bits
 */

// @lc code=start
bool compare(int a, int b)
{
    int x = __builtin_popcount(a);
    int y = __builtin_popcount(b);
    if (x == y)
    {
        return a < b;
    }
    return x < y;
}
class Solution
{
public:
    vector<int> sortByBits(vector<int> &arr)
    {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};
// @lc code=end
