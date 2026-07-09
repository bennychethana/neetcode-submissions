class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        while(l<=n-1 && nums[l]%2==0) l++;
        while(r>=0 && nums[r]%2!=0) r--;
        while(l<r){
            int t = nums[l];
            nums[l] = nums[r];
            nums[r] = t;
            while(l<=n-1 && nums[l]%2==0) l++;
            while(r>=0 && nums[r]%2!=0) r--;
        }
        return nums;
    }
};