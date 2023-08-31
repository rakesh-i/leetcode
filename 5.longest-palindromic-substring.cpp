/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxlen =1;
        int start=0;
        int dp[1001][1001] = {0};
        for(int j=0; j<n; j++){
            for(int i=0; i<j; i++){
                if(s[i]==s[j]&&(j-i<=2||dp[i+1][j-1]==1)){
                    dp[i][j] = 1;
                    if(j-i+1>maxlen){
                        maxlen = j-i+1;
                        start = i;
                    }
                    
                }
            }
        }
        return s.substr(start, maxlen);
    }
};
// @lc code=end

