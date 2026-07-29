class Solution {
public:
    int at_most_k(vector<int>& nums, int k){
        int left = 0;
        int n = nums.size();
        unordered_map<int,int> map;
        int ans = 0;
        for(int i=0;i<n;i++){
            map[nums[i]]++;
            if(map.size()<=k){
                ans += i-left+1;
            }
            while(map.size()>k){
                map[nums[left]]--;
                if(map[nums[left]]==0) map.erase(nums[left]);
                left++;
                if(map.size()<=k){
                    ans += i-left+1;
                }
            }
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return at_most_k(nums,k) - at_most_k(nums,k-1);
    }
};

// at_most_k easier
// at any valid index i, no of subarrays with at most k ending at i = i-left+1
// if not valid, shrink left till valid again

// 1,2,1,2,3 

// 1
// 12,2
// 121,21,1
// 1212,212,12,2
// 23,3
// =12

// exactly_k = at_most_k - at_most_k-1

