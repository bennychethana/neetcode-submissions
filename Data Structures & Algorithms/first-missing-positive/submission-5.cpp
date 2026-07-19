class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<0) nums[i] = 0;
            if(nums[i]>n) nums[i] = 0;
        }
        for(int i=0;i<n;i++){
            int num = abs(nums[i]);
            if(num==n+1 || num==0) continue;
            int index = num-1;
            if(nums[index]==0){
                nums[index] = -(n+1);
            }
            else nums[index] = -abs(nums[index]);
        }
        for(int i=0;i<n;i++){
            if(nums[i]>=0) return i+1;
        }
        return n+1;
    }
};