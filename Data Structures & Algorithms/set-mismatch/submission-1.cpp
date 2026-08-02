class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> set;
        vector<int> ans;
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            if(set.count(nums[i])){
                ans.push_back(nums[i]);
            }
            else{
                set.insert(nums[i]);
                sum+=nums[i];
            }
        }
        int missing = (n*(n+1))/2 - sum;
        ans.push_back(missing);
        return ans;
    }
};