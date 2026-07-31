class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(i!=0 && nums[i]==nums[i-1]) continue;
            int num = nums[i];
            int target = -num;
            int left = i+1;
            int right = n-1;
            while(left<n && right>-1 && left<right){
                int sum = nums[left]+nums[right];
                if(sum>target){
                    right--;
                }
                else if(sum<target){
                    left++;
                }
                else if(sum==target){
                    ans.push_back({num,nums[left],nums[right]});
                    right--;
                    left++;
                    while(left!=n && nums[left]==nums[left-1]) left++;
                    while(right!=-1 && nums[right]==nums[right+1]) right--;
                }
            }
        }
        return ans;
    }
};

// -4 -1 -1 0 1 2

// -2 1 1

// -5 -3 -2 -1 0 0 0 1 1 1 3 4 4


