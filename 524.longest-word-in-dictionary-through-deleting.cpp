/*
 * @lc app=leetcode id=524 lang=cpp
 *
 * [524] Longest Word in Dictionary through Deleting
 */

// @lc code=start
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int n = s.size();
        int m = dictionary.size();
        string res = "";
        for(int i=0; i<m; i++){
            int x = dictionary[i].size();
            if(x>n){
                continue;
            }
            else{
                int j=0;
                int k=0;
                while(j<x&&k<n){
                    if(dictionary[i][j]==s[k]){
                        j++;
                        k++;
                    }
                    else{
                        k++;
                    }
                }
                if(j==x){
                    if(res.size()==x){
                        if(res>dictionary[i]){
                            res = dictionary[i];
                        }
                    }
                    else if(res.size()<x){
                        res = dictionary[i];
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

