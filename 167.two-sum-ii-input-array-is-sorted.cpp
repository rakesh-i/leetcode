/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n =  numbers.size();
        int a = 0;
        int b = n-1;
        while(a<b){
            int mid = (a+b)/2;
            if(numbers[a]+numbers[b]==target){
                return {a+1, b+1};
            }
            else if(numbers[a]+numbers[b]>target){
                b--;
            }
            else{
                a++;
            }
        }
        return {};
    }
};
// @lc code=end

