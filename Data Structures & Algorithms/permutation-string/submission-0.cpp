class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> s1_map;
        int n = s1.size();
        for(int i=0;i<n;i++){
            s1_map[s1[i]]++;
        }
        int need = s1_map.size();
        if(n>s2.size()) return false;
        int m = s2.size();
        unordered_map<char,int> s2_map;
        int have = 0;
        int left = 0;
        for(int i=0;i<m;i++){
            s2_map[s2[i]]++;
            char ch = s2[i];
            if(s1_map[ch]==s2_map[ch]){
                have++;
                if(have == need) return true;
            }
            if(i-left+1==n){
                char ch2 = s2[left];
                if(s1_map[ch2]==s2_map[ch2]) have--;
                s2_map[ch2]--;
                if(s2_map[ch2]==0) s2_map.erase(ch2);
                left++;
            }
        }
        return false;
    }
};
