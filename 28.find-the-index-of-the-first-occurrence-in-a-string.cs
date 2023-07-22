/*
 * @lc app=leetcode id=28 lang=csharp
 *
 * [28] Find the Index of the First Occurrence in a String
 */

// @lc code=start
public class Solution {
    public int StrStr(string haystack, string needle) {
        int res =-1;
        char s = needle[0];
        int m = needle.Length;
        int n  = haystack.Length;
        for(int i = 0; i<n; i++){
            int j = 0;
            int prev = i;
            if(haystack[i]==s){
                while(i<n&&j<m){
                    if(haystack[i]!=needle[j]){
                        break;
                    }
                    j++;
                    i++;
                }
                if(j==m){
                    res = i-j;
                    break;
                }
                i = prev;
            }
        }
        return res;
    }
}
// @lc code=end

