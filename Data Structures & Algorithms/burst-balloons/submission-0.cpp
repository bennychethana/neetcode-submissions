class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> balloons;
        balloons.push_back(1);
        for (int num : nums) {
            balloons.push_back(num);
        }
        balloons.push_back(1);
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        for (int len = 1; len <= n; len++){
            for (int i=1;i<=n;i++){
                int j = i+len-1;
                if(j>n) continue;
                int m = 0;
                for (int k = i; k <= j; k++){// check which gives max coins
                    int cur_last_burst = balloons[i-1]*balloons[k]*balloons[j+1];
                    int cur_coins = dp[i][k-1]+cur_last_burst+dp[k+1][j];
                    m = max(m,cur_coins);
                }
                dp[i][j] = m;
            }
        }  
        return dp[1][n]; 
    }
};

// 4,2,3,7

// dp[i][j] = max coins obtainable by bursting every balloon in the contiguous interval [i...j], 
//             with the balloons immediately outside the interval (i-1 and j+1) still intact.

// dp(i, j) =
//     max over k in [i...j] {
//         dp(i, k-1)
//       + nums[i-1] * nums[k] * nums[j+1]
//       + dp(k+1, j)
//     }

// for (len = 1; len <= n; len++)
//     for (all intervals of length len)
//         for (k = i; k <= j; k++)