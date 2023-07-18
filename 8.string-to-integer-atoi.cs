/*
 * @lc app=leetcode id=8 lang=csharp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
public class Solution {
    public int MyAtoi(string s) {
        int m = int.MaxValue/10;
        int i=0;
        int sign = 1;
        int n = s.Length;
        int num = 0;
        while(i<n&&s[i]==' '){
            i++;
        }
        if(i<n&&(s[i]=='-'||s[i]=='+')){
            sign= (s[i]=='-')?-1:1;
            i++;
        }
        while(i<n&&s[i]>=48&&s[i]<=57){
            if(num>m||(num==m&&((s[i]-'0'))>7)){
                return sign==-1?int.MinValue: int.MaxValue;
            }
            num = num*10+(s[i]-'0');
            i++;
        }
        return sign*num;
    }
}
// @lc code=end

