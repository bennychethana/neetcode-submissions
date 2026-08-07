class Solution {
public:
    bool is_valid(string s){
        int n = s.size();
        bool start = s[0]=='a' || s[0]=='e' || s[0]=='i' || s[0]=='o' || s[0]=='u'; 
        bool end = s[n-1]=='a' || s[n-1]=='e' || s[n-1]=='i' || s[n-1]=='o' || s[n-1]=='u'; 
        return start && end;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> pre(n,0);
        pre[0] = is_valid(words[0]) ? 1 : 0;
        for(int i=1;i<n;i++){
            if(is_valid(words[i])){
                pre[i] = pre[i-1]+1;
            }
            else pre[i] = pre[i-1];
        }
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int l = queries[i][0];
            int r = queries[i][1];
            if(l==0) ans.push_back(pre[r]);
            else ans.push_back(pre[r]-pre[l-1]);
        }
        return ans;
    }
};