/*
 * @lc app=leetcode id=1525 lang=cpp
 *
 * [1525] Number of Good Ways to Split a String
 */

// @lc code=start
class Solution {
public:
    int numSplits(string s) {
        map<char, int> l, r;
        int n = s.size();
        l[s[0]]++;
        for(int i=1; i<n; i++){
            r[s[i]]++;
        }
        int res = 0;
        for(int i=1; i<n; i++){
            if(l.size()==r.size()){
                res++;
            }
            l[s[i]]++;
            r[s[i]]--;
            if(r[s[i]]==0){
                r.erase(s[i]);
            }
        }
        return res;
    }
};
// @lc code=end

