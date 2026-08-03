class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int some_num = 0;
        for(int i=0;i<n;i++){
            if(nums[i]<=0 || nums[i]>n) nums[i] = 0;
            else{
                some_num = nums[i];
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]==0) nums[i] = some_num;
        }
        if(nums[0]==0) return 1;
        for(int i=0;i<n;i++){
            cout<<nums[i]<<" "<<endl;
        }
        for(int i=0;i<n;i++){
            int num = nums[i];
            int ind = abs(num)-1;
            nums[ind] = -(abs(nums[ind]));
        }
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                return i+1;
            }
        }
        return n+1;
    }
};

//  2  2 1 2
// -2 -2 1 2