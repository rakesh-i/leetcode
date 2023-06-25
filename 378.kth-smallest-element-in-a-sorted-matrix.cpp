/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */

// @lc code=start
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> a;
        int n = matrix.size();
        for(int i = 0; i<n; i++){
            for(int j=0; j<n; j++){
                a.push_back(matrix[i][j]);
            }
        }
        sort(a.begin(), a.end());

        return a[k-1];
    }
};
// @lc code=end

