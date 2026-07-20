class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0;
        int y = 0;
        unordered_set<string> set;
        int n = path.size();
        set.insert(to_string(0)+"-"+to_string(0));
        for(int i=0;i<n;i++){
            if(path[i]=='N'){
                y-=1;
            }
            else if(path[i]=='S'){
                y+=1;
            }
            else if(path[i]=='E'){
                x+=1;
            }
            else if(path[i]=='W'){
                x-=1;
            }
            string coord = to_string(x)+"-"+to_string(y);
            if(set.count(coord)) return true;
            set.insert(coord);
        }
        return false;
    }
};