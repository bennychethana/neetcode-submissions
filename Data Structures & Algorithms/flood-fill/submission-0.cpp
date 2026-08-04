class Solution {
public:
    int m = 0;
    int n = 0;
    int y[4] = {-1,0,1,0};
    int x[4] = {0,1,0,-1};
    vector<vector<bool>> visited;
    void f(int i, int j, vector<vector<int>>& image, int color, int org_color){
        if(i<0 || i>m-1 || j<0 || j>n-1) return;
        if(visited[i][j]) return;
        if(image[i][j]!=org_color) return;
        visited[i][j] = true;
        image[i][j] = color;
        for(int d=0;d<4;d++){
            int nbr_i = i + y[d];
            int nbr_j = j + x[d];
            f(nbr_i,nbr_j,image,color,org_color);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size();
        n = image[0].size();
        visited = vector<vector<bool>>(m,vector<bool>(n,false));
        f(sr,sc,image,color,image[sr][sc]);
        return image;
    }
};