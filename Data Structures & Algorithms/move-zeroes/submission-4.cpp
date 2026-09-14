class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0; // first 0 
        int n = nums.size();
        while(l<n && nums[l]!=0) l++;
        if(l>=n-1) return;
        for(int i=l;i<nums.size();i++){
            if(nums[i]!=0){
                // swap with left 0
                nums[l] = nums[i];
                nums[i] = 0;
                while(l<n && nums[l]!=0) l++;
                if(l>=n-1) return;
            }
        }
    }
};