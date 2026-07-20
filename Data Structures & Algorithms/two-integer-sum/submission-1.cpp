class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            int need = target - nums[i];
            if(map.count(need)){
                ans.push_back(map[need]);
                ans.push_back(i);
                return ans;
            }
            map[nums[i]] = i;
        }
        return {};
    }
};
