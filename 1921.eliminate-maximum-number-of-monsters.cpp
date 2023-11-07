/*
 * @lc app=leetcode id=1921 lang=cpp
 *
 * [1921] Eliminate Maximum Number of Monsters
 */

// @lc code=start
class Solution
{
public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed)
    {
        int n = dist.size();
        vector<float> at;
        for (int i = 0; i < n; i++)
        {
            float x = (float)dist[i] / (float)speed[i];
            at.push_back(x);
        }
        sort(at.begin(), at.end());
        if (n == 1)
        {
            return 1;
        }
        int count = 1;
        // for(auto i:at){
        //     cout<<i<<endl;
        // }
        for (int i = 1; i < n; i++)
        {
            if (at[i] - float(i) <= 0.0)
            {
                break;
            }
            else
            {
                count++;
            }
        }
        return count;
    }
};
// @lc code=end
