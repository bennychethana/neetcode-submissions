class Solution {
public:
    bool is_substring(string a, string b){
        int m = a.size();
        int n = b.size();
        for(int i=0;i<n-m+1;i++){
            string sub = b.substr(i,m);
            if(sub==a) return true;
        }
        return false;
    }
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        unordered_set<string> set;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                string small = "";
                string big = "";
                if(words[i].size()<=words[j].size()){
                    small = words[i];
                    big = words[j];
                }
                else{
                    small = words[j];
                    big = words[i];
                }
                if(is_substring(small,big)){
                    set.insert(small);
                }
            }
        }
        vector<string> ans;
        for(auto &it:set){
            ans.push_back(it);
        }
        return ans;
    }
};