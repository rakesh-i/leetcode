/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int m = 0;
        int cur = 0;
        int n =s.size();
        stack<int> st;
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                st.push(i);
            }
            else{
                if(!st.empty()){
                    if(s[st.top()]=='('){
                        st.pop();
                    }
                    else{
                        st.push(i);
                    }
                }
                st.push(i);
            }
        }
        if(st.empty()){
            return n;
        }
        int a = n; int b=0;
        while(!st.empty()){
            b = st.top(); 
            st.pop();
            m = max(m, a-b-1);
        }
        return m;
    }
};
// @lc code=end

