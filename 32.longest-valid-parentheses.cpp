/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int start = 0;
        int mx = 0;
        for(int i=1; i<=s.size(); i++){
            if(s[i-1]=='('){
                st.push(i);
            }
            else{
                if(st.empty()){
                    start = i;
                    continue;
                }
                else{
                    st.pop();
                    if(st.empty()){
                        mx = max(mx, i-start);
                    }
                    else{
                        mx = max(mx, i-st.top());
                    }
                }
            }
        }
        return mx;
    }
};
// @lc code=end

