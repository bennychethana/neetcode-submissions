class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // flip diagonall
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int t = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = t;
            }
        }
        // flip to left
        for(int i=0;i<n;i++){
            for(int j=0;j<n/2;j++){
                int t = matrix[i][j];
                matrix[i][j] = matrix[i][n-j-1];
                matrix[i][n-j-1] = t;
            }
        }
    }
};

// 1 2 3   9 6 3   1 4 7
// 4 5 6   8 5 2   2 5 8
// 7 8 9   7 4 1   3 6 9

// 1 2     4 2
// 3 4     3 1