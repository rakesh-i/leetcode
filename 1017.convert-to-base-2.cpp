/*
 * @lc app=leetcode id=1017 lang=cpp
 *
 * [1017] Convert to Base -2
 */

// @lc code=start
class Solution {
public:
    string baseNeg2(int n) {
        string res = "";
        if(n==0){
            return "0";
        }
        while(n!=0){
            int x = n % -2;
            n = n/(-2);
            if(x<0){
                x +=2;
                n +=1; 
            }
            string y = to_string(x);
            res = y+res;
        }
        return res;
    }
};
// @lc code=end

