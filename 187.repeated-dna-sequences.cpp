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
        set<string> a;
        int n = s.length();
        for(int i=0;i<n-9; i++){
            string str= s.substr(i, 10);
            if(++m[str]>1){
                a.insert(str);
            }
        }
        vector<string> res;
        for(auto itr :a){
            res.push_back(itr);
        }
        return res;
    }
};
// @lc code=end

