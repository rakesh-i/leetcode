/*
 * @lc app=leetcode id=1641 lang=cpp
 *
 * [1641] Count Sorted Vowel Strings
 */

// @lc code=start
class Solution {
public:
    int count = 0;
    void helper(int idx, int x, int n){
        if(x==n){
            count++;
            return;
        }
        for(int i = idx; i<5; i++){
            helper(i, x+1, n);
        }

    }
    int countVowelStrings(int n) {
        helper(0, 0, n);
        return count;
    }
};
// @lc code=end

