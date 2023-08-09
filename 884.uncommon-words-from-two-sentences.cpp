/*
 * @lc app=leetcode id=884 lang=cpp
 *
 * [884] Uncommon Words from Two Sentences
 */

// @lc code=start
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        int i = 0;
        s1 = s1 +" "+ s2+" "; 
        unordered_map<string, int> m;
        while(s1[i]!='\0'){
            string s = "";
            while(s1[i]!=' '&& s1[i]!='\0'){
                s += s1[i];
                i++;
            }
            i++;
            m[s]++;
        }
        vector<string>res;
        for(auto i:m){
            if(i.second == 1 ){
                res.push_back(i.first);
            }
        }
        return res;


    }
};
// @lc code=end

