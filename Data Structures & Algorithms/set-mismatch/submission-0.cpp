class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> set;
        int n = nums.size();
        int duplicate = 0;
        for(int i=0;i<n;i++){
            if(set.count(nums[i])){
                duplicate = nums[i];
                break;
            }
            set.insert(nums[i]);
        }
        int actual_sum = 0;
        for(int i=0;i<n;i++){
            actual_sum+= nums[i];
        }
        int expected_sum = (n*(n+1))/2;
        int missing = expected_sum + duplicate - actual_sum;
        return {duplicate,missing};
    }
};

// expected_sum = n(n+1)/2
// actual_sum = s
// actual_sum = expected_sum - missing + duplicate