class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        deque<int> q; // index
        for(int i=0;i<n;i++){
            while(!q.empty() && nums[q.back()]<=nums[i]){
                q.pop_back();
            }
            q.push_back(i);
            while(q.front()<i-k+1){
                q.pop_front();
            }
            if(i>=k-1){
                ans.push_back(nums[q.front()]);
            }
        }
        return ans;
    }
};

// q
// for new element, pop from back while q value less that new value

// if q size>k, pop until size<k

// push to ans the q back element