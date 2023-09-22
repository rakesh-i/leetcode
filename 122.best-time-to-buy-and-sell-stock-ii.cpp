/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mn = prices[0];
        int mx = 0;
        for(int i=1; i<n; i++){
            if(prices[i]>mn){
                mx +=prices[i]-mn;
                mn = prices[i];
            }
            if(prices[i]<mn){
                mn = prices[i];
            }
        }
        return mx;
    }
};
// @lc code=end

