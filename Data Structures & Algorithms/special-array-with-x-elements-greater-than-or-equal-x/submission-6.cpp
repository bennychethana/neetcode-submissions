class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n;i++){
            int s = n-i;
            if(s<=nums[i]){
                // if(i==0) continue;
                if(i==0 || nums[i-1]<s) return s;
            }
        }
        return -1;
    }
};

// 0 3 6 7 7
// 5 4 3 2 1

// 4 4 4 4 4 4 4
// 7 6 5 4 3 2 1

// x: 0 to n

// 0 0 3 4 4
// 5 4 3 2 1

// 0 0 
// 2 1

// 3 5
// 2 1