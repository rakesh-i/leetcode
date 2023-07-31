/*
 * @lc app=leetcode id=566 lang=csharp
 *
 * [566] Reshape the Matrix
 */

// @lc code=start
public class Solution {
    public int[][] MatrixReshape(int[][] mat, int r, int c) {
        int[][] a = new int[r][];
        int n = mat.Length;
        int m = mat[0].Length;
        if(n*m!=c*r){
            return mat;
        }
        for(int i=0; i<r; i++){
            a[i] = new int[c];
        }
        int x = 0; 
        int y = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(y<c){
                    a[x][y++] = mat[i][j];
                }
                else{
                    y=0;
                    a[++x][y++] = mat[i][j];
                }
            }
        }
        return a;

    }
}
// @lc code=end

