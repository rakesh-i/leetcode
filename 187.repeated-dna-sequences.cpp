/*
 * @lc app=leetcode id=187 lang=cpp
 *
 * [187] Repeated DNA Sequences
 */

// @lc code=start
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> m;
        int n = s.length();
        for(int i=0;i<n-9; i++){
            string str= s.substr(i, 10);
            m[str]++;
        }
        vector<string> res;
        for(auto &i : m){
            if(i.second>1){
                res.push_back(i.first);
            }
        }
        return res;
    }
};
// @lc code=end

