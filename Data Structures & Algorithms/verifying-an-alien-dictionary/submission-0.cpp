class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int n = words.size();
        bool ans = true;
        unordered_map<char,int> map;
        for(int i=0;i<order.size();i++){
            map[order[i]] = i;
        }
        bool ok = false;
        for(int i=1;i<n;i++){
            int prev_len = words[i-1].size();
            int cur_len = words[i].size();
            int l = min(prev_len,cur_len);
            int it = 0;
            ok = false;
            while(it<l){
                if(map[words[i-1][it]]<map[words[i][it]]){
                    ok = true;
                    break;
                }
                else if(map[words[i-1][it]]>map[words[i][it]]){
                    cout<<" breaking at "<<words[i-1][it]<<endl;
                    ans = false;
                    break;
                }
                it++;
            }
            if(!ok && ans && words[i-1].size()>words[i].size()) return false;
            if(!ans) return false;
        }
        return ans;
    }
};