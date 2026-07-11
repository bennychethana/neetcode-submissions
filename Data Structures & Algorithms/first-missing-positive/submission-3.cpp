class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int positives = 0;
        int some_positive = 0;
        for(int i=0;i<n;i++){
            if(nums[i]<=0 || nums[i]>n) nums[i]=0;
            else{
                positives++;
                some_positive = nums[i];
            }
        }
        if(positives==0) return 1;
        if(n==1){
            if(nums[0]==1) return 2;
            else return 1;
        }
        for(int i=0;i<n;i++){
            if(nums[i]==0) nums[i]=some_positive;
        }
        // possibile : 1, 2, ... n
        // 6 0 0 1 2 4 0 0 5
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                int index = abs(nums[i])-1;
                nums[index] = -abs(nums[index]);
            }
        }
        for(int i=0;i<n;i++){
            cout<<nums[i]<<" ";
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                return i+1;
            }
        }
        return n+1;
    }
};