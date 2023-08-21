/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int x) {
        int n = nums.size();
        unordered_map<int, vector<int>> m;
        for(int i=0; i<n; i++){
            m[nums[i]].push_back(i);
        }
        for(auto i:m){
            if(i.second.size()>=2){
                for(int j=0; j<i.second.size(); j++){
                   for(int k=j+1; k<i.second.size(); k++){
                       if(i.second[k]-i.second[j]<=x){
                           return true;
                       }
                   }
                }
                //cout<<endl;
            }
            
        }
        
        return false;
    }
};
// @lc code=end

