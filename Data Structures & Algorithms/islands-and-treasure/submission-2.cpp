class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<tuple<int,int,int>> q; // i,j,dist
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    q.push({i,j,0});
                }
            }
        }
        int y[4] = {-1,0,1,0};
        int x[4] = {0,1,0,-1};
        int INF = 2147483647;
        while(!q.empty()){
            auto [i,j,dist] = q.front();
            q.pop();
            for(int d=0;d<4;d++){
                int nbr_i = i + y[d];
                int nbr_j = j + x[d];
                if(nbr_i<0 || nbr_i>m-1 || nbr_j<0 || nbr_j>n-1) continue;
                if(grid[nbr_i][nbr_j]==INF){// unvisited land
                    q.push({nbr_i,nbr_j,dist+1});
                    grid[nbr_i][nbr_j] = dist+1;
                }
            }
        }
    }
};

// bfs from treasure cells
// store cell and dist in q

