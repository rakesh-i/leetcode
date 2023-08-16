/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 */
#include<vectors>
// @lc code=start
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        int n = s.size();
        for(int i=0; i<n; i++){
            m[s[i]]++;
        }
        map<int, vector<char>> o;
        for(auto i: m){
            o[i.second].push_back(i.first);
        }
        string res = "";
        for(auto i=o.rbegin(); i!=o.rend();i++){
            vector<char> x = i->second;
            for(int j=0; j<x.size(); j++){
                for(int k=0; k<i->first; k++){
                    res += x[j];
                }
            }
        }
        return res;
    }
};
// @lc code=end

