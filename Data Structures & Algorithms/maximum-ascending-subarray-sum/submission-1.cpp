class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int max_sum = nums[0];
        int n = nums.size();
        int sum = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]<=nums[i-1]){
                sum = nums[i];
                continue;
            }
            sum+=nums[i];
            max_sum = max(max_sum,sum);
        }
        return max_sum;
    }
};