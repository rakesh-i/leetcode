/*
 * @lc app=leetcode id=275 lang=cpp
 *
 * [275] H-Index II
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& c) {
        int n = c.size();
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(c[mid]>=n-mid){
                high = mid-1;
                //cout<<"hh"<<curr<<" "<<c[mid]<<endl;
            }
            else {
                low = mid+1;
                //cout<<"jj"<<curr<<" "<<c[mid]<<endl;
            }
        }
        return n-low;
    }
};
// @lc code=end

