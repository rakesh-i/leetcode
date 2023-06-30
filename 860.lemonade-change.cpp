/*
 * @lc app=leetcode id=860 lang=cpp
 *
 * [860] Lemonade Change
 */

// @lc code=start
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int, int> b;
        if(bills[0]>5){
            return false;
        }
        for(int i=0; i<bills.size(); i++){
            if(bills[i]==5){
                b[5]++;
            }
            if(bills[i]==10){
                b[10]++;
                if(b[5]){
                    b[5]--;
                }
                else{
                    return false;
                }
            }
            if(bills[i]==20){
                b[20]++;
                if(b[5]&&b[10]){
                    b[5]--;
                    b[10]--;
                }
                else if(b[5]>=3){
                    b[5]--;
                    b[5]--;
                    b[5]--;
                }
                else{
                    return false;
                }
            }
        }
        return true;
        
    }
};
// @lc code=end

