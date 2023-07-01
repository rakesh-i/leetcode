/*
 * @lc app=leetcode id=969 lang=cpp
 *
 * [969] Pancake Sorting
 */

// @lc code=start
class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> a;
        while(arr.size()>0){
            int m = max_element(arr.begin(), arr.end())-arr.begin()+1;
            if(m==arr.size()){
                arr.pop_back();
            }
            else if(m==1){
                int n = arr.size();
                for(int i=0; i<n/2; i++){
                    swap(arr[i], arr[n-i-1]);
                }
                a.push_back(n);
                arr.pop_back();
            }
            else{
                a.push_back(m);
                for(int i=0; i<m/2; i++){
                    swap(arr[i], arr[m-i-1]);
                }
                int n = arr.size();
                for(int i=0; i<n/2; i++){
                    swap(arr[i], arr[n-i-1]);
                }
                a.push_back(n);
                arr.pop_back();
            }
        }
        return a;
    }
};
// @lc code=end

