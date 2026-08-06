class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        for(int i=0;i<secondList.size();i++){
            firstList.push_back(secondList[i]);
        }
        sort(firstList.begin(),firstList.end());
        vector<vector<int>> ans;
        int prev_end = firstList[0][1];
        for(int i=1;i<firstList.size();i++){
            int cur_start = firstList[i][0];
            int cur_end = firstList[i][1];
            if(cur_start<=prev_end){
                ans.push_back({cur_start,min(cur_end,prev_end)});
            }
            prev_end = max(cur_end,prev_end);
        }
        return ans;
    }
};

// 0,2  5,10    13,23   24,25
// 1,5  8,12    15,24   25,26

// 0,10 1,2 2,3 7,15