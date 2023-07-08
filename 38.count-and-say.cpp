/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */

// @lc code=start
class Solution {
public:
    void helper(int x, string &s){
        if(x==1){
            s = "1";
            return;
        }
        helper(x-1, s);
        int n = s.size();
        string z = s;
        s = "";
        for(int i=0; i<n; i++){
            char x = z[i];
            int count = 0;
            while(i<n&&z[i]==x){
                count++;
                i++;
            }
            if(n==1){
                s = to_string(count)+x;
            }
            else{
                s += to_string(count)+x;
                i--;
            }
            
        }

    }

    string countAndSay(int n) {
        string s = "";
        helper(n, s);
        return s;
    }
};
// @lc code=end

