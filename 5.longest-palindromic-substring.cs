/*
 * @lc app=leetcode id=5 lang=csharp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
public class Solution {
    public int check(string s, int i, int j){
        int m = (j-i)/2;
        int bb = i;
        for(int k=i; k<m+bb+1; k++){
            if(s[k]!=s[j]){
                return 0;
            }
            j--;
        }
        return 1;
    }
    public string LongestPalindrome(string s) {
        int n = s.Length;
        int w = n;
        for(int i=n-1; i>=0; i--){
            int b = 0;
            int e = i;
            for(int k = i; k<n; k++){
                string sub = s.Substring(b, e+1);
                if(check(s, b, k)==1){
                    return sub;
                }
                b++;
            }
        }
        string res = "";
        return res+s[0];
    }
}
// @lc code=end

