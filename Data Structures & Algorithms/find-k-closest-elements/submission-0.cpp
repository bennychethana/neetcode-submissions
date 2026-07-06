class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        priority_queue<pair<int,int>> maxheap;
        for(int i=0;i<n;i++){
            int diff = abs(arr[i]-x);
            maxheap.push({diff,arr[i]});
            if(maxheap.size()>k){
                maxheap.pop();
            }
        }
        vector<int> ans;
        while(!maxheap.empty()){
            int element = maxheap.top().second;
            ans.push_back(element);
            maxheap.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};