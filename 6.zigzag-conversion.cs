/*
 * @lc app=leetcode id=6 lang=csharp
 *
 * [6] Zigzag Conversion
 */

// @lc code=start
public class Solution {
    public string Convert(string s, int numRows) {
        List<List<char>> a = new List<List<char>>();
        for(int i=0; i<numRows; i++){
            a.Add(new List<char>());
        }
        int n = s.Length;
        for(int i=0; i<n; i++){
            int row = 0;
            while(i<n&&row<numRows){
                a[row].Add(s[i]);
                i++;
                row++;
            }
            row--;
            row--;
            while(i<n&&row>=1){
                a[row].Add(s[i]);
                i++;
                row--;
            }
            i--;
        }
        string res = "";
        for(int j=0; j<a.Count; j++){
            for(int i = 0; i<a[j].Count; i++){
                res+=a[j][i];
            }
        }
        return res;
    }
}
// @lc code=end

