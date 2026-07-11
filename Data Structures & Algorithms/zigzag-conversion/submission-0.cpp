class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        int i=0;
        vector<vector<char>> v(numRows);
        int row = 0;
        string dir = "down";
        while(i<n){
            v[row].push_back(s[i]);
            if(dir=="up"){
                row--;
                dir = "up";
            }
            else{
                row++;
            }
            if(row==numRows){
                dir="up";
                row=row-2;
            }
            if(row==-1){
                dir="down";
                row=row+2;
            }
            i++;
        }
        string ans = "";
        for(auto &it: v){
            for(auto& c:it){
                ans+=c;
            }
        }
        return ans;
    }
};