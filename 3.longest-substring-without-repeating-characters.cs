/*
 * @lc app=leetcode id=3 lang=csharp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
public class Solution {
    public int LengthOfLongestSubstring(string s) {
        var m = new HashSet<char>();
        int i = 0;
        int j = 0;
        int mm = 0;
        int n = s.Length;
        

        while(i<n){ 
            if(m.Contains(s[i])==false){
                m.Add(s[i]);
                i++;
                mm = Math.Max(mm, m.Count);
            }
            else{
                m.Remove(s[j]);
                j++;
            }
            
        }
        return mm;
        
    }
}
// @lc code=end

