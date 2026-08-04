class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v_s(26,0);
        vector<int> v_t(26,0);
        for(int i=0;i<s.size();i++){
            v_s[s[i]-'a']++;
        }
        for(int i=0;i<t.size();i++){
            v_t[t[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(v_s[i]!=v_t[i]) return false;
        }
        return true;
    }
};
