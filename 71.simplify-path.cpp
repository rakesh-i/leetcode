/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string res;
        int n = path.size();
        for(int i=0; i<n; i++){
            if(path[i]=='/'){
                continue;
            }
            string temp = "";
            while(i<n&&path[i]!='/'){
                temp +=path[i];
                i++;
            }
            if(temp == "."){
                continue;
            }
            if(temp == ".."){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(temp);
            }
        }
        if(st.empty()){
            return "/";
        }
        while(!st.empty()){
            res = "/"+st.top()+res;
            st.pop();
        }
        
        return res;
        
    }
};
// @lc code=end

