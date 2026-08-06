class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        int n = s.size();
        unordered_set<char> set;
        int left = 0;
        for(int i=0;i<n;i++){
            while(set.count(s[i])){
                set.erase(s[left]);
                left++;
            }
            set.insert(s[i]);
            max_len = max(max_len,i-left+1);
        }
        return max_len;
    }
};
