/*
 * @lc app=leetcode id=441 lang=cpp
 *
 * [441] Arranging Coins
 */

// @lc code=start
class Solution {
public:
    int arrangeCoins(int n) {
        long low = 1;
        long high = n;
        while(low<=high){
            long mid = (high+low)>>1;
            long sum = mid*(mid+1) >> 1;
            if(sum==n){
                return mid;
            }
            else if(sum>n){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low-1;
    }
};
// @lc code=end

