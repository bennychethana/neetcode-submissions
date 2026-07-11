class Solution {
public:
    int at_most(vector<int>& nums, int k){
        int n = nums.size();
        unordered_map<int,int> map;
        int left = 0;
        int cnt = 0;
        for(int i=0;i<n;i++){
            map[nums[i]]++;
            while(map.size()>k){
                map[nums[left]]--;
                if(map[nums[left]]==0){
                    map.erase(nums[left]);
                }
                left++;
            }
            cnt = cnt + (i-left+1);
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return at_most(nums,k) - at_most(nums,k-1);
    }
};