class Solution {
public:
    int f(vector<int>& nums, int target, int cur_sum, vector<int>& dp){
        if(cur_sum==target){
            return 1;
        }
        if(cur_sum > target) return 0;
        if(dp[cur_sum]!=-1) return dp[cur_sum];
        // action
        //try every combination for the next position
        dp[cur_sum] = 0;
        for(int i=0;i<nums.size();i++){
            dp[cur_sum] = dp[cur_sum] + f(nums,target,cur_sum+nums[i],dp);
        }
        return dp[cur_sum];
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1); // number of ways to reach target starting from current sum i
        return f(nums,target,0,dp);
    }
};