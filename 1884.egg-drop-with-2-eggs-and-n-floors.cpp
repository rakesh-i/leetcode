/*
 * @lc app=leetcode id=1884 lang=cpp
 *
 * [1884] Egg Drop With 2 Eggs and N Floors
 */

// @lc code=start
class Solution {
public:
    int twoEggDrop(int n) {
        int temp = 0;
        int cur = 1;
        while(n>0){
            n -=cur;
            cur++;
            temp++;
        }
        return temp;
    }
};
// @lc code=end

