class Solution {
public:
    int bs(int lo, int hi, vector<int>& nums, int target){
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target) lo = mid+1;
            else hi = mid-1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int min = INT_MAX;
        int min_ind = 0;
        for(int i=0;i<n;i++){
            if(nums[i]<min){
                min = nums[i];
                min_ind = i;
            }
        }
        cout<<nums[min_ind]<<endl;
        if(nums[min_ind]==target) return min_ind;
        if(nums[0]==target) return 0;
        if(nums[n-1]==target) return n-1;
        int ans = -1;
        if(min_ind==0) ans = bs(1,n-1,nums, target);
        else if(target>=nums[0] && target<=nums[min_ind-1]){
            ans = bs(0,min_ind-1,nums, target);
        }
        else{
            ans = bs(min_ind+1,n-1,nums, target);
        }
        return ans;
    }
};

// find min
// search in leaft and right halfs of min