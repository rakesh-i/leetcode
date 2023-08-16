/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */

// @lc code=start
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = pattern.size();
        s = s+" ";
        int i=0;
        int count = 0;
        vector<string> a;
        map<string, int> mp;
        while(s[i]!='\0'){
            string x = "";
            while(s[i]!=' '){
                x += s[i];
                i++;
            }
            mp[x]++;
            a.push_back(x);
            i++;
        }
        map<char,vector<int>> m;
        for(int i=0; i<n; i++){
            m[pattern[i]].push_back(i);
        }
        cout<<mp.size()<<" "<<m.size()<<endl;
        if(mp.size()!=m.size()){
            return false;
        }
        for(auto i:m){
            int x = i.second.size();
            string b = a[i.second[0]];
            if(mp.find(b)==mp.end()){
                return false;
            }
            if(x!=mp[b]){
                return false;
            }
            for(int j=0; j<x; j++){
                if(b!=a[i.second[j]]){
                    return false;
                }
            }
            mp.erase(b);
        }
        return true;
    }
};
// @lc code=end

