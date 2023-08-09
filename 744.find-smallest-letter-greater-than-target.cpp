/*
 * @lc app=leetcode id=744 lang=cpp
 *
 * [744] Find Smallest Letter Greater Than Target
 */

// @lc code=start
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int y = target-'a';
        for(int i=0; i<n; i++){
            int x = letters[i]-'a';
            if(x>y){
                return letters[i];
            }
        }
        return letters[0];
    }
};
// @lc code=end

