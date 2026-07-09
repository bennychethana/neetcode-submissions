class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size(); 
        unordered_map<char,int> common_map;
        for(int i=0;i<words[0].size();i++){
            common_map[words[0][i]]++;
        }
        for(int i=1;i<n;i++){
            unordered_map<char,int> cur_map;
            for(int j=0;j<words[i].size();j++){
                cur_map[words[i][j]]++;
            }
            for(auto &it: common_map){
                it.second = min(cur_map[it.first],it.second);
            }
        }
        vector<string> ans;
        for(auto &it: common_map){
            int cnt = it.second;
            // string s = to_string(it.first);
            string s = string(1, it.first);
            while(cnt--){
                ans.push_back(s);
            }
        }
        return ans;
    }
};