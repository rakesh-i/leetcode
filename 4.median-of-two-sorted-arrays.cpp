/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int x = 0; 
        int y = 0;
        vector<int> a;
        while(x<n&&y<m){
            if(nums1[x]<=nums2[y]){
                a.push_back(nums1[x]);
                x++;
            }
            else{
                a.push_back(nums2[y]);
                y++;
            }
        }
        while(x<n){
            a.push_back(nums1[x]);
            x++;
        }
        while(y<m){
            a.push_back(nums2[y]);
            y++;
        }
        if((n+m)%2==0){
            if((n+m)==2){
                return float((float(a[0])+float(a[1]))/float(2));
            }
            else{
                int z = (n+m)/2; 
                return float((float(a[z])+float(a[z-1]))/float(2));
            }
            
        }
        else{
            int z = (n+m)/2;
            return float(a[z]);
        }
        return 0.0;
    }
};
// @lc code=end

