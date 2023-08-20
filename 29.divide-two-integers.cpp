/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor){
            return 1;
        }
        unsigned int ans = 0;
        unsigned int x = abs(dividend);
        unsigned int y = abs(divisor);
        while(x>=y){
            short q = 0;
            while(x>(y<<(q+1)))
                q++;
            ans += (1<<q);
            x = x - (y<<q);
        }
        if(dividend<0&&divisor<0){
            if(ans>=2147483648){
                return INT_MAX;
            }
            return ans;
        }
        if(dividend<0&&divisor>0||dividend>0&&divisor<0){
            if(ans<-2147483648){
                return INT_MIN;
            }
            ans = -ans;
        }
        return ans;
    }
};
// @lc code=end

