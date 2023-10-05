/*
 * @lc app=leetcode id=2131 lang=cpp
 *
 * [2131] Longest Palindrome by Concatenating Two Letter Words
 */

// @lc code=start
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int res = 0;
        unordered_map<string, int> m;
        for(auto s:words){
            string p = s;
            reverse(p.begin(), p.end());
            if(m[p]>0){
                res+=4;
                m[p]--;
            }
            else{
                m[s]++;
            }
        }
        for(auto i:m){
            if(i.first[0]==i.first[1]&&i.second>0){
                return res+2;
            }
        }
        return res;
    }
};
// @lc code=end

