/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
public:
    unordered_map<string, bool> m;
    bool helper(string s,vector<string>&wordDict){
        if(s.size()==0){
            return true;
        }
        if(m.find(s)!=m.end()){
            return m[s];
        }
        bool ans = false;
        for(int i=wordDict.size()-1; i>=0; i--){
            int a = wordDict[i].size();
            if(s.size()>=a){
                string x = s.substr(0, a);
                if(wordDict[i]==x){
                    ans = helper(s.substr(a), wordDict);
                    if(ans==true){
                        break;
                    }
                }
            }
        }
        return m[s] = ans;

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        //reverse(s.begin(), s.end());
        return helper(s, wordDict);
    }
};
// @lc code=end

