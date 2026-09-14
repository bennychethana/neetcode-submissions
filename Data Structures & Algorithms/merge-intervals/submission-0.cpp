class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            int s = ans.size();
            int last_end = ans[s-1][1];
            if(intervals[i][0]>last_end){
                ans.push_back(intervals[i]);
            }
            else{
                ans[s-1][1] = max(ans[s-1][1],intervals[i][1]);
            }
        }
        return ans;
    }
};

// 
