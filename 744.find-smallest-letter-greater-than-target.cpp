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
        int i=0; 
        int j=n-1;
        while(i<=j){
            int mid = (j+i)/2;
            if(letters[mid]>target){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return i == n?letters[0]:letters[i];
    }
};
// @lc code=end

