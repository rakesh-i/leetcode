/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 */

// @lc code=start
class Solution {
public:
    void merger(vector<int> &l, int s, int mid, int e){
        vector<int> a,b;
        for(int i=s; i<=mid; i++){
            a.push_back(l[i]);
        }
        for(int i=mid+1; i<=e; i++){
            b.push_back(l[i]);
        }
        int n = a.size();
        int m = b.size();
        int i=0, j=0, k=s;
        while(i<n&&j<m){
            if(a[i]>=b[j]){
                l[k++] = b[j++];
            }
            else{
                l[k++] = a[i++];
            }
        }
        while(i<n){
            l[k++] = a[i++];
        }
        while(j<m){
            l[k++] = b[j++];
        }

    }
    void devide(vector<int> &l, int s, int e){
        if(s>=e){
            return;
        }
        int mid = s+(e-s)/2;
        devide(l, s, mid);
        devide(l, mid+1, e);
        merger(l, s, mid, e);
    }
    vector<int> sortArray(vector<int>& nums) {
        vector<int> l;
        devide(nums, 0, nums.size()-1);
        return nums;
    }
};
// @lc code=end

