/*
 * @lc app=leetcode id=859 lang=cpp
 *
 * [859] Buddy Strings
 */

// @lc code=start
class Solution {
public:
    bool buddyStrings(string s, string g) {
        if(s.length()!=g.length()){
            return false;
        }
        if(s==g&&set<char>(s.begin(), s.end()).size()<g.size()){
            return true;
        }
        vector<int> d;
        for(int i=0; i<s.size(); i++){
            if(s[i]!=g[i]){
                d.push_back(i);
            }
        }
        return d.size()==2&&s[d[0]]==g[d[1]]&&s[d[1]]==g[d[0]];

    }
};
// @lc code=end

