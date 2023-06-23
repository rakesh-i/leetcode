/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
class Solution {
public:
    long CalculateCoeff(int n,int k) //Function to calculate Ci(n.k)
    {
        long res=1;
        if(k>n-k)
            k=n-k;                    //Since Ci(n,k)=Ci(n,n-k), property of binomial coefficients
        for(int i=0;i<k;i++)
        {
            res*=(n-i);
            res/=(i+1);
        }
        return res;
    }
    int numTrees(int n) {
        return CalculateCoeff(2*n,n)/(n+1);
    }
};
// @lc code=end

