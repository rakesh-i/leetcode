/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
class Solution {
public:
    int fib(int n, vector<int> &l){
        if(l[n]!=-1){
            return l[n];
        }
        if(n<0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        
        l[n] = fib(n-1,l)+fib(n-2,l);
        return l[n];

    }
    int fib(int n) {
       vector<int> l(31, -1);
        l[0] = 0;
        l[1] = 1;
    //    return 0;
       return fib(n, l);
    }
};
// @lc code=end

