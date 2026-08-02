class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int> map;
        int n = words.size();
        int c = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<words[i].size();j++){
                map[words[i][j]]++;
                c++;
            }
        }
        if(c%n!=0) return false;
        for(auto &it:map){
            if(it.second%n!=0) return false;
        }
        return true;
    }
};