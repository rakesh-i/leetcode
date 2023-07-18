/*
 * @lc app=leetcode id=9 lang=csharp
 *
 * [9] Palindrome Number
 */

// @lc code=start
public class Solution {
    public bool IsPalindrome(int x) {
        if(x<0){
            return false;
        }
        string s = x.ToString();
        int n = s.Length;
        for(int i=0; i<n; i++){
            if(s[i]!=s[n-1-i]){
                return false;
            }
        }
        return true;
    }
}
// @lc code=end

