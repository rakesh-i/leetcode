/*
 * @lc app=leetcode id=2305 lang=cpp
 *
 * [2305] Fair Distribution of Cookies
 */

// @lc code=start
class Solution {
public:
    int helper(vector<int>& cookies, vector<int>& temp, int idx, int k, int zerocount){
        if(cookies.size()-idx<zerocount){
            return INT_MAX;
        }
        if(idx==cookies.size()){
            int mx = INT_MIN;
            for(int i=0; i<k; i++){
                mx = max(mx, temp[i]);
            }
            return mx;
        }
        int ans = INT_MAX;
        for(int i=0; i<k; i++){
            zerocount-=temp[i]==0?1:0;
            temp[i] += cookies[idx];
            ans = min(ans, helper(cookies, temp, idx+1, k, zerocount));
            temp[i]-=cookies[idx];
            zerocount+=temp[i]==0?1:0;
        }
        return ans;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> temp(k, 0);
        return helper(cookies, temp, 0, k, k);
    }
};
// @lc code=end

