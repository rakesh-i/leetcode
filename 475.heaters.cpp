/*
 * @lc app=leetcode id=475 lang=cpp
 *
 * [475] Heaters
 */

// @lc code=start
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int n = houses.size();
        int m = heaters.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            int x = lower_bound(heaters.begin(), heaters.end(), houses[i])-heaters.begin();
            int right = x>=m?INT_MAX:heaters[x]-houses[i];
            int left = x-1<0?INT_MAX: houses[i]-heaters[x-1];
            // cout<<x<<endl;
            ans = max(ans, min(left, right));
        }
        
        
        return ans;
    }
};
// @lc code=end

