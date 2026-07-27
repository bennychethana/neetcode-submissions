class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pos = 0;
        int neg = 0;
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                pos = i;
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                neg = i;
                break;
            }
        }
        while(pos<n && neg<n && ans.size()!=n){
            cout<<"pos: "<<pos<<endl;
            cout<<"neg: "<<neg<<endl;
            ans.push_back(nums[pos]);
            ans.push_back(nums[neg]);
            pos++;
            neg++;
            while(pos<n && nums[pos]<0){
                pos++;
            }
            while(neg<n && nums[neg]>0){
                neg++;
            }
        }
        return ans;
    }
};