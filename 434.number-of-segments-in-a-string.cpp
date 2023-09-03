/*
 * @lc app=leetcode id=434 lang=cpp
 *
 * [434] Number of Segments in a String
 */

// @lc code=start
class Solution {
public:
    int countSegments(string s) {
        int n = s.length();
        s = s+' ';
        int count=0;
        for(int i=0; i<n+1; i++){
            if(s[i]==' '){
                continue;
            }
            else{
                while(s[i]!=' '){
                    i++;
                }
                count++;
                i--;
            }
        }
        return count;
    }
};
// @lc code=end

