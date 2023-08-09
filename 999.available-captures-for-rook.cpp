/*
 * @lc app=leetcode id=999 lang=cpp
 *
 * [999] Available Captures for Rook
 */

// @lc code=start
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int n = 8;
        int r = 0;
        int c = 0; 
        int flag = 0;
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                if(board[i][j]=='R'){
                    r=i;
                    c=j;
                    flag=1;
                    break;
                }
            }
            if(flag==1){
                break;
            }
        }
        int ans = 0;
        for(int i=c; i<8; i++){
   
            if(board[r][i]=='B'){
                break;
            }
            else if(board[r][i]=='p'){
                ans++;
                break;
            }
        }
 
        for(int i=c; i>=0; i--){
    
            if(board[r][i]=='B'){
                break;
            }
            else if(board[r][i]=='p'){
                ans++;
                break;
            }
        }

        for(int i=r; i<8; i++){
  
            if(board[i][c]=='B'){
                break;
            }
            if(board[i][c]=='p'){
                ans++;
                break;
            }
        }

        for(int i=r; i>=0; i--){
  
            if(board[i][c]=='B'){
                break;
            }
            else if(board[i][c]=='p'){
                ans++;
                break;
            }
        }

        return ans;
    }
};
// @lc code=end

