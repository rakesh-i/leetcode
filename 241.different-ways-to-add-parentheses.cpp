/*
 * @lc app=leetcode id=241 lang=cpp
 *
 * [241] Different Ways to Add Parentheses
 */

// @lc code=start
class Solution {
public:
    vector<int> diffWaysToCompute(string exp) {
        int n = exp.length();
        vector<int> res;
        for(int i=0; i<n; i++){
            char x = exp[i];
            if(x=='*'||x=='-'||x=='+'){
                vector<int> left = diffWaysToCompute(exp.substr(0,i));
                vector<int> right = diffWaysToCompute(exp.substr(i+1));
                for(auto j:left){
                    for(auto k:right){
                        if(x=='*'){
                            res.push_back(j*k);
                        }
                        else if(x=='-'){
                            res.push_back(j-k);
                        }
                        else{
                            res.push_back(j+k);
                        }
                    }
                }
            }
        }
        if(res.empty()){
            res.push_back(stoi(exp));
        }
        return res;
    }
};
// @lc code=end

