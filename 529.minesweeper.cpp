/*
 * @lc app=leetcode id=529 lang=cpp
 *
 * [529] Minesweeper
 */

// @lc code=start
class Solution {
public:
    bool inboard(const vector<vector<char>>& board, int x, int y){
        return ( x>=0 && x<board.size() && y>=0 && y<board[0].size() );
    }
    
    void dfs(vector<vector<char>>& board, int x, int y)
    {
        // boundary condition..
        if(!inboard(board,x,y)) return;
        if(board[x][y] == 'B') return;
        
        // if it is 'E' then go forward recursively 
        // check 8 adjacent squares & count all mines adjacent to board[x][y], and place count to the current 
        // position of board[x][y]
        int count = 0;
        if(inboard(board,x-1,y-1) && board[x-1][y-1] == 'M') count++;
        if(inboard(board,x-1,y  ) && board[x-1][y  ] == 'M') count++;
        if(inboard(board,x-1,y+1) && board[x-1][y+1] == 'M') count++;
        if(inboard(board,x  ,y-1) && board[x  ][y-1] == 'M') count++;
        if(inboard(board,x  ,y+1) && board[x  ][y+1] == 'M') count++;
        if(inboard(board,x+1,y-1) && board[x+1][y-1] == 'M') count++;
        if(inboard(board,x+1,y  ) && board[x+1][y  ] == 'M') count++;
        if(inboard(board,x+1,y+1) && board[x+1][y+1] == 'M') count++;
        
        // set board with different values either 'count' or 'B' 
        if(count>0)
            board[x][y] = '0'+count;
        else
        {
            board[x][y] = 'B';
            // search recursively in 8 directions
            dfs(board,x-1,y-1);
            dfs(board,x-1,y  );
            dfs(board,x-1,y+1);
            dfs(board,x  ,y-1);
            dfs(board,x  ,y+1);
            dfs(board,x+1,y-1);
            dfs(board,x+1,y  );
            dfs(board,x+1,y+1);
        }
    }
    
    // Return the board after revealing this position according to the following rules
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        
        // m X n character matrix
        // first click start from ----> (r, c)
        int r = click[0];
        int c = click[1];
        if(board[r][c] == 'M'){
            board[r][c]= 'X';
            return board;
        }
        
        dfs(board, r, c);
        return board;
    }
};
// @lc code=end

