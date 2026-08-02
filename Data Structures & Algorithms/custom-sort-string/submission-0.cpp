class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> s_map;
        for(int i=0;i<s.size();i++){
            s_map[s[i]]++;
        }
        string ans = "";
        for(int i=0;i<order.size();i++){
            while(s_map.count(order[i])){
                ans+=order[i];
                s_map[order[i]]--;
                if(s_map[order[i]]==0) s_map.erase(order[i]);
            }
        }
        for(auto &it:s_map){
            while(it.second!=0){
                ans+=it.first;
                it.second--;
            }
        }
        return ans;
    }
};