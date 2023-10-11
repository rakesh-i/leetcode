/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int sell = 0;
        int buy = INT_MIN;
        for(auto i:prices){
            buy = max(buy, sell-i);
            sell = max(sell, buy+i-fee);
        }
        return sell;
    }
};
// @lc code=end

