class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // return nums[nums.size()/2];
        int num = nums[0];
        int cnt = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==num){
                cnt++;
            }
            else{
                cnt--;
                if(cnt==0){
                    num = nums[i];
                    cnt = 1;
                }
            }
        }
        return num;
    }
};

// num cnt
// 5   1
//     2
//     1
// 1   0
//     1
// 5   0


// cur_num==num cnt==
// else cnt--
// if(cnt==0) num = cur_num