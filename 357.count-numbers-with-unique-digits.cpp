/*
 * @lc app=leetcode id=357 lang=cpp
 *
 * [357] Count Numbers with Unique Digits
 */

// @lc code=start
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)return 1;
        long int ans=10;
        
        for(int i=2;i<=n;i++){
            long int ct=9,t=i-1,j=9;
            while(t--){
                ct*=j;
                j--;
            }
            ans+=ct;
        }
        
        return ans;
    }
};
// @lc code=end

