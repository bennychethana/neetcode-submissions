class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0){
                    dp[i][j] = points[i][j];
                }
                else{
                    int m = 0;
                    for(int k=0;k<n;k++){// prev row
                        int loss = abs(j-k); 
                        m = max(m,dp[i-1][k]-loss+points[i][j]);
                    }
                    dp[i][j] = m;
                }
            }
        }
        int ans = 0;
        for(int j=0;j<n;j++){
            ans = max(ans,dp[m-1][j]);
        }
        return ans;
    }
};

// dp[i][j] = max points till row i by last taking jth col in row i
// = for all j dp[i-1][j]

// for(int j=0;j<n;j++){// cur row
//     int m = 0;
//     for(int k=0;k<n;j++){// prev row
//         int loss = abs(j-k); 
//         m = max(m,dp[i-1][k]-loss+points[i][j]);
//     }
//     dp[i][j] = m;
// }