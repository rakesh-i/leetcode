#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;


/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        for(int i=0; i<nums.size(); i++){
            int sum = target - nums[i];
            if(m.find(sum)!=m.end()){
                return {m[sum],i};
            }
            m[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end

