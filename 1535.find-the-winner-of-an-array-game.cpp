/*
 * @lc app=leetcode id=1535 lang=cpp
 *
 * [1535] Find the Winner of an Array Game
 */

// @lc code=start
class Solution
{
public:
    int getWinner(vector<int> &arr, int k)
    {
        int n = arr.size();
        if (k >= n)
        {
            return *max_element(arr.begin(), arr.end());
        }
        int c = 0;
        int i = 0;
        while (c != k)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i + 1];
                arr.push_back(temp);
                arr[i + 1] = arr[i];
                i++;
                c++;
            }
            else
            {
                c = 1;
                int temp = arr[i];
                arr.push_back(temp);
                i++;
            }
        }
        return arr[i];
    }
};
// @lc code=end
