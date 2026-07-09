class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n,0);
        if(n==1){
            return stoneValue[0]>0 ? "Alice" : "Bob";
        }
        dp[n-1] = stoneValue[n-1];
        dp[n-2] = max(stoneValue[n-2]-dp[n-1],stoneValue[n-2]+stoneValue[n-1]);
        if(n==2){
            return dp[0]>0 ? "Alice" : "Bob";
        }
        dp[n-3] = max({stoneValue[n-3]-dp[n-2], stoneValue[n-3]+stoneValue[n-2]-dp[n-1], stoneValue[n-3]+stoneValue[n-2]+stoneValue[n-1]});
        for(int i=n-4;i>=0;i--){
            int take1 = stoneValue[i] - dp[i+1];
            int take2 = stoneValue[i] + stoneValue[i+1] - dp[i+2];
            int take3 = stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - dp[i+3];
            dp[i] = max({take1,take2,take3});
        }
        if(dp[0]==0) return "Tie";
        return dp[0]>0 ? "Alice" : "Bob";
    }
};

// dp[i] = max score diff that can be achieved from i to end
//       = max(take1,take2,take3)

// take1 = val[i] - dp[i+1]
// take2 = val[i] + val[i+1] - dp[i+2]
// take3 = val[i] + val[i+1] + val[i+2] - dp[i+3]