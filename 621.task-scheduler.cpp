/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

// @lc code=start
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> m;
        int count = 0;
        for(auto i:tasks){
            m[i]++;
            count = max(count, m[i]);
        }
        int ans = (count-1)*(n+1);
        for(auto i:m){
            if(i.second== count){
                ans++;
            }
        }
        return max(ans, int(tasks.size()));
    }
};
// @lc code=end

