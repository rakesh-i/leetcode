/*
 * @lc app=leetcode id=299 lang=cpp
 *
 * [299] Bulls and Cows
 */

// @lc code=start
class Solution {
public:
    string getHint(string secret, string guess) {
        map<int, int> m;
        int a = 0;
        int b = 0;
        int l = secret.size();
        for(int i=0; i<l; i++){
            m[secret[i]]++;
        }

        for(int i=0; i<l; i++){
            if(secret[i]==guess[i]){
                a++;
            }
            if(m.find(guess[i])!=m.end()){
                b++;
                if(m[guess[i]]==1){
                    m.erase(guess[i]);
                }
                else{
                    m[guess[i]]--;
                }
            }
        }
        b = b-a;
        string x = to_string(a);
        string y = to_string(b);
        return x+"A"+y+"B";


    }
};
// @lc code=end

