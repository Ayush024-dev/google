// qp link: https://www.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1?page=2&company=Google&sortBy=difficulty
/*
Approach (Simple Explanation):
Initialize a DP Table:

Create a dp table of the same size as mat, where dp[i][j] will store the maximum side length of a square ending at position (i, j).

Initially, assume each cell in dp has a value of 1.

Traverse the Matrix:

Loop through every cell (i, j) in mat.

Handle Zeroes:

If mat[i][j] == 0, set dp[i][j] = 0 because a square can't be formed with a 0 and continue.

Check Neighboring Cells:

For mat[i][j] == 1, determine the minimum square size possible by looking at:

left (dp[i][j-1]): Maximum square ending at the left cell.

top (dp[i-1][j]): Maximum square ending at the top cell.

diagonal (dp[i-1][j-1]): Maximum square ending at the diagonal top-left cell.

The new square size at (i, j) is 1 + min(left, top, diagonal).

Track the Maximum Square Size:

Keep updating maxi to store the largest square size found so far.

Return Result:

The answer is stored in maxi, which gives the side length of the largest square of 1s.

Time Complexity:
O(n * m) since we iterate through the matrix once and update dp values in constant time.

Space Complexity:
O(n * m) due to the additional dp table.
*/
class Solution {
  public:
    int maxSquare(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        
        vector<vector<int>> dp(n, vector<int> (m, 1));
        
        
        
        int maxi=0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==0){
                    dp[i][j]=0;
                    continue;
                }
                
                int left=0;
                
                if(j-1>=0) left=dp[i][j-1];
                
                int top=0;
                
                if(i-1>=0) top=dp[i-1][j];
                
                int dia=0;
                
                if(i-1>=0 && j-1>=0) dia=dp[i-1][j-1];
                
                dp[i][j]=1+min(dia, min(top, left));
                maxi=max(maxi, dp[i][j]);
            }
        }
        
        return maxi;
    }
};
