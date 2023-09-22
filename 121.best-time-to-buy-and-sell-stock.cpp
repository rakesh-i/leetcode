/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mn = prices[0];
        int mx = 0;
        for(int i=0; i<n; i++){
            if(prices[i]>mn){
                mx = max(mx, prices[i]-mn);
            }
            if(mn>prices[i]){
                mn = prices[i];
            }
        }
        return mx;
    }
};
// @lc code=end

