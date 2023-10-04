/*
 * @lc app=leetcode id=877 lang=cpp
 *
 * [877] Stone Game
 */

// @lc code=start
class Solution {
public:
    int dp[501][501];
    int helper(vector<int>&piles, int alice, int bob, int flag, int i, int j, int count){
        if(count==piles.size()){
            if(alice>bob){
                return 1;
            }
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int a = 0;
        int b = 0;
        if(flag==1){
            a = max(helper(piles, alice+piles[i], bob, 0, i+1, j, count+1),helper(piles, alice+piles[j], bob, 0, i, j-1, count+1) );
        }
        else{
            b = max(helper(piles, alice, bob+piles[i], 1, i+1, j, count+1),helper(piles, alice, bob+piles[j], 1, i, j-1, count+1) );
        }
        return dp[i][j] = max(b,a);
    }
    bool stoneGame(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        return helper(piles, 0, 0, 1, 0, piles.size()-1, 0);
    }
};
// @lc code=end

