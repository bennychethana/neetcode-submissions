class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_set<int> set;
        int n = grid.size();
        int extra = 0;
        int missing = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(set.count(grid[i][j])) extra = grid[i][j];
                set.insert(grid[i][j]);
            }
        }
        for(int i=1;i<=n*n;i++){
            if(!set.count(i)){
                missing = i;
                return {extra,missing};
            }
        }
        return {};
    }
};