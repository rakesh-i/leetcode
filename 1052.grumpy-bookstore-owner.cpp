/*
 * @lc app=leetcode id=1052 lang=cpp
 *
 * [1052] Grumpy Bookstore Owner
 */

// @lc code=start
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        std::ios::sync_with_stdio(false); 
        cin.tie(nullptr); 
        cout.tie(nullptr); 
        int n = customers.size();
        int count = 0;
        int mx = 0;
        int sum = 0;
        for(int j=0; j<n; j++){
            if(grumpy[j]==0){
                count+=customers[j];
            }
        }
        mx = count;
        for(int i=0;i<n-minutes+1; i++){
            int x = i;
            sum = count;
            for(int k=i; k<x+minutes; k++ ){
                if(grumpy[k]==1){
                    sum+=customers[k];
                }
            }
            mx = max(mx, sum);
        }
        
        return mx;
    }
};
// @lc code=end

