class Solution {
public:
    int f(int start, vector<int>& nums){
        int n = nums.size();
        vector<int> dp(n-1,0);
        dp[0] = nums[start];
        dp[1] = max(nums[start],nums[start+1]);
        for(int i=2;i<=n-2;i++){
            dp[i] = max(dp[i-1],dp[i-2]+nums[start+i]);
        }
        return dp[n-2];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        int dp1 = f(0,nums);
        int dp2 = f(1,nums);
        return max(dp1,dp2);
    }
};
