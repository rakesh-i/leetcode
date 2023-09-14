/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 */

// @lc code=start
class Solution {
public:
    int dp[101][101];
    int helper(string s1, string s2, string s3, int l1, int l2, int l3){
        if(l1<0&&l2<0&&l3<0){
            return 1;
        }
        if(l1>=0&&l2>=0&&dp[l1][l2]!=-1){
            return dp[l1][l2];
        }
        if(l1>=0&&l2>=0&&s1[l1]==s3[l3]&&s2[l2]==s3[l3]){
            return dp[l1][l2] = helper(s1, s2, s3, l1-1, l2, l3-1)||helper(s1, s2, s3, l1, l2-1, l3-1);
        }
        else if(l1>=0&&s1[l1]==s3[l3]){
            return helper(s1, s2, s3, l1-1, l2, l3-1);
        }
        else if(l2>=0&&s2[l2]==s3[l3]){
            return helper(s1, s2, s3, l1, l2-1, l3-1);
        }
        else {
            return 0;
        }
    }
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n=s2.size(), o = s3.size(); 
        if(o!=m+n){
            return false;
        }
        memset(dp, -1, sizeof(dp));
        return helper(s1, s2, s3, m-1, n-1, o-1);
    }
};
// @lc code=end

