/*
 * @lc app=leetcode id=1638 lang=cpp
 *
 * [1638] Count Substrings That Differ by One Character
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s, string t) {
        int res = 0;
        for(int i=0; i<s.size(); i++){
            for(int j=0; j<t.size(); j++){
                int miss = 0;
                for(int cur=0; cur+i<s.size()&&cur+j<t.size(); cur++){
                    if(s[i+cur]!=t[j+cur]&&++miss>1){
                        break;
                    }
                    res+=miss;
                }
            }
        }
        return res;
    }
};
// @lc code=end

