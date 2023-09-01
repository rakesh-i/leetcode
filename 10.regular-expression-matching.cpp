/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
    int n = p.length();

    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;  // Empty string matches empty pattern

    // Fill the first row (empty string s)
    for (int j = 1; j <= n; j++) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 2];  // Zero occurrence of preceding character
        }
    }
    for(int i=0; i<n+1; i++){
        for(int j=0; j<m+1; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    // Fill the DP matrix
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
            }
        }
    }
    for(int i=0; i<n+1; i++){
        for(int j=0; j<m+1; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return dp[m][n];
    }
};
// @lc code=end

