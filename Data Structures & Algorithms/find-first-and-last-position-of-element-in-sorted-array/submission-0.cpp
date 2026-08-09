class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0;
        int hi = n;
        vector<int> ans = {0,0};
        while(lo<hi){ // f f f t t t
            int mid = (lo+hi)/2;
            if(nums[mid]>=target) hi = mid;
            else lo = mid+1;
        }
        if(lo<0 || lo>n-1) return {-1,-1};
        if(nums[lo]!=target) return {-1,-1};
        ans[0] = lo;
        lo = 0;
        hi = n;
        while(lo<hi){ // f f f t t t
            int mid = (lo+hi)/2;
            if(nums[mid]>target) hi = mid;
            else lo = mid+1;
        }
        if(lo-1<0 || lo-1>n-1) return {-1,-1};
        if(nums[lo-1]!=target) return {-1,-1};
        ans[1] = lo-1;
        return ans;
    }
};

// f f f t t t

