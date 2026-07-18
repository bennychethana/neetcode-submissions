class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int n = arr.size();
        for(int i=k;i<n;i++){
            if(abs(x-arr[i])<abs(x-arr[left])){
                left++;
            }
        }
        vector<int> ans;
        for(int i=left;i<left+k;i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};

// 2 3 4
// x=4, k=2