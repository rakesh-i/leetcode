/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = p.size();
        vector<int> m(26,0);
        for(int i=0; i<n; i++){
            m[p[i]-'a']++;
        }
        
        vector<int> b;
        vector<int> res;
        int x = s.size();
        for(int i=0; i<x-n+1; i++){
            int c = 0;
            b = m;
            int flag=0;
            for(int j=i; j<i+n; j++){
                if(b[s[j]-'a']>0&&flag==0){
                    c++;
                    b[s[j]-'a']--;   
                }
                else{
                    flag=1;
                }
            }
            if(c==n){
                res.push_back(i);
            }
        }
        return res;
    }
};
// @lc code=end

