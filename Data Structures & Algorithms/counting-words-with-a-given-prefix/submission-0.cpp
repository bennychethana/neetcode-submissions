class Solution {
public:
    bool starts_with(string a, string pref){
        if(a.size()<pref.size()) return false;
        for(int i=0;i<pref.size();i++){
            if(a[i]!=pref[i]) return false;
        }
        return true;
    }
    int prefixCount(vector<string>& words, string pref) {
        int n = words.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            if(starts_with(words[i],pref)) ans++;
        }
        return ans;
    }
};