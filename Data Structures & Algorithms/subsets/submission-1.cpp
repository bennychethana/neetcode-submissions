class Solution {
public:
    vector<vector<int>> ans;
    int n = 0;
    void f(int i,vector<int>& cur_subset,vector<int>& nums){
        if(i==n){
            ans.push_back(cur_subset);
            return;
        }
        cur_subset.push_back(nums[i]);
        f(i+1,cur_subset,nums);
        cur_subset.pop_back();
        f(i+1,cur_subset,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur_subset;
        n = nums.size();
        f(0,cur_subset,nums);
        return ans;
    }
};
