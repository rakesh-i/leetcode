/*
 * @lc app=leetcode id=7 lang=csharp
 *
 * [7] Reverse Integer
 */

// @lc code=start
public class Solution {
    public int Reverse(int x) {
        string s = x.ToString();
        //Console.WriteLine(s);
        char[] chars = s.ToCharArray();
        Array.Reverse(chars);
        string a = new string(chars);
        if(x<0){
            a = a.Substring(0, a.Length-1);
            a = '-'+a;
        }
        try{
            int y = Int32.Parse(a);
            return y;
        }
        catch(Exception e){
            return 0;
        }
    }
}
// @lc code=end

