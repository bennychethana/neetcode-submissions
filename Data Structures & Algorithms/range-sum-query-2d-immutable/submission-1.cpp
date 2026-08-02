class NumMatrix {
public:
    int n = 0;
    int m = 0;
    vector<vector<int>> pre_sum;
    NumMatrix(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        pre_sum = vector<vector<int>>(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0) pre_sum[i][j] = matrix[i][j];
                else if(i==0) pre_sum[i][j] = pre_sum[i][j-1] + matrix[i][j];
                else if(j==0) pre_sum[i][j] = pre_sum[i-1][j] + matrix[i][j];
                else{
                    pre_sum[i][j] = pre_sum[i-1][j] + pre_sum[i][j-1] + matrix[i][j] - pre_sum[i-1][j-1];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int up = row1-1>=0 ? pre_sum[row1-1][col2] : 0;
        int left = col1-1>=0 ? pre_sum[row2][col1-1] : 0;
        int common = (row1-1>=0 && col1-1>=0) ? pre_sum[row1-1][col1-1] : 0;
        return pre_sum[row2][col2] - up - left + common;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */