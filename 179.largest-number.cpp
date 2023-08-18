/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */

// @lc code=start
class Solution {
public:
    int comp(int n, int m){
        string nm = to_string(n)+to_string(m);
        string mn = to_string(m)+to_string(n);
        return nm>mn; 
    }
    void merger(vector<int> &l, int s, int mid, int e){
        vector<int> a, b;
        for(int i=s; i<=mid; i++){
            a.push_back(l[i]);
        }
        for(int i=mid+1; i<=e; i++){
            b.push_back(l[i]);
        }
        int n = a.size(), m = b.size();
        int i=0, j=0, k=s;
        while(i<n&&j<m){
            if(comp(a[i], b[j])==1){
                l[k++] = a[i++];
            }
            else{
                l[k++] = b[j++];
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
    string largestNumber(vector<int>& nums) {
        devide(nums, 0, nums.size()-1);
        string res = "";
        for(int i=0; i<nums.size(); i++){
            res += to_string(nums[i]);
        }
        if(res[0]=='0'){
            return "0";
        }
        return res;
    }
};
// @lc code=end

