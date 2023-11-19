/*
 * @lc app=leetcode id=1887 lang=cpp
 *
 * [1887] Reduction Operations to Make the Array Elements Equal
 */

// @lc code=start
class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int, int> m;
        int n = nums.size();
        for(int i=0; i<n; i++){
            m[nums[i]]++;
        }
        if(m.size()==1){
            return 0;
        }
        int count=0;
        int prev = 0;
        map<int, int> ::reverse_iterator rit;
        for(rit = m.rbegin(); rit!=m.rend(); rit++){
            count+=rit->second+prev;
            prev = rit->second+prev;
        }
        return count-n;
    }
};
// @lc code=end

