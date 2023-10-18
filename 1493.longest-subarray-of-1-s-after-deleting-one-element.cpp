/*
 * @lc app=leetcode id=1493 lang=cpp
 *
 * [1493] Longest Subarray of 1's After Deleting One Element
 */

// @lc code=start
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(0);
        vector<vector<int>> m;
        int i = 0;
        while(i<n){
            int c = 0;
            int cur = i;
            while(nums[i]==1){
                c++;
                i++;
            }
            if(c){
                m.push_back({cur, c});
                i--;
            }
            i++;

        }
        if(m.size()==0){
            return 0;
        }
        int mx = m[0][1];
        for(int i=1; i<m.size(); i++){
            int x = max(m[i][1], m[i-1][1]);
            mx = max(x, mx);
            if(m[i][0]-(m[i-1][0]+m[i-1][1])==1){
                mx = max(mx, m[i-1][1]+m[i][1]);
            }
        }
        return mx==n?mx-1:mx;
    }
};
// @lc code=end

