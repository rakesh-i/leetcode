/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
class Solution {
public:
    int dp[101];
    int helper(string s, int idx, string cur){
      if(s[idx]=='0'){
        return 0;
      }
      if(idx==s.size()){
        return 1;
      }
      if(dp[idx]!=-1){
        return dp[idx];
      }
      int ans = 0;
      string x = "";
      for(int i = idx; i<s.size()&&i<idx+2; i++){
        x = x+s[i];
        if(stoi(x)<27){
          ans +=helper(s, i+1, x);
        }
      }
      return dp[idx] = ans;

    }
    int numDecodings(string s) {
      memset(dp, -1, sizeof(dp));
      return helper(s, 0, "");
    }
};
// @lc code=end

