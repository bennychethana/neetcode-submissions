class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> balloons;
        balloons.push_back(1);
        for(int i=0;i<n;i++){
            balloons.push_back(nums[i]);
        }
        balloons.push_back(1);
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        for(int len=1;len<=n;len++){
            for(int i=1;i<n+1;i++){
                int j = i+len-1;
                if(j>n) continue;
                int max_coins = 0;
                for(int k=i;k<=j;k++){
                    int cur_coins = dp[i][k-1] + balloons[i-1]*balloons[k]*balloons[j+1] + dp[k+1][j];
                    max_coins = max(max_coins,cur_coins);
                }
                dp[i][j] = max_coins;
            }
        }
        return dp[1][n];
    }
};


// dp[i][j] = max coins from bursting [i...j] inclusive
// for len: 1 to l, 
// = max over k[i...j], k being the last baloon to burst
// int max_coins = 0;
// = for(int k=1;k<=j;k++){
//     int cur_coins = dp[i][k-1] + nums[i-1]*nums[k]*nums[j+1] + dp[k+1][j];
//     max_coins = max(max_coins,cur_coins);
// }
// dp[i][j] = max_coins;

// d123d

// 1 2 3 4 