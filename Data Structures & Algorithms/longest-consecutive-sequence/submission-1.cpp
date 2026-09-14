class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int num = INT_MAX;
        unordered_set<int> set;
        for(int i=0;i<nums.size();i++){
            set.insert(nums[i]);
        }
        int ans = 0;
        int len = 0;
        for(auto num:set){
            if(!set.count(num-1)){// num is a start
                len = 0;
                while(set.count(num)){
                    len++;
                    num++;
                }
                ans = max(ans,len);
            }
        }
        return ans;
    }
};
