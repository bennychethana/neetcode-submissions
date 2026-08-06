class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,0));
        for(int i=0;i<=coins.size();i++){
            for(int j=0;j<=amount;j++){
                if(i==0 && j==0) continue;
                if(i==0){
                    dp[i][j] = amount+1;
                    continue;
                }
                else if(j==0) continue;
                if(coins[i-1]==j){
                    dp[i][j] = 1;
                }
                else if(coins[i-1]>j){
                    dp[i][j] = dp[i-1][j];
                }
                else if(coins[i-1]<j){
                    dp[i][j] = min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
                }
            }
        }
        // return dp[coins.size()][amount];
        return dp[coins.size()][amount] == amount+1
            ? -1
            : dp[coins.size()][amount];
    }
};


// dp[i][j] = min coins to from [0...i] to make j
// = if(i>j) -> dp[i-1][j]
// if(i==j) ->1
// if(i<j) -> min(use coin, dont use coin) = min(1+dp[i][j-coins[i]],dp[i-1][j])

//     0 1 2 3 4 5
// 0   0 I I I I I
// 1   0 1 2 3 4 5
// 5   0 1 2 3 4 1
// 10  

//     0 1 2 3
// 0   0 I I I
// 2   0 0 1 1