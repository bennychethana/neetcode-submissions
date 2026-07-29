class Solution {
public:
    bool isPrefixAndSuffix(string s1, string s2){
        int len1 = s1.size();
        int len2 = s2.size();
        if(len1>len2) return false;
        for(int i=0;i<len1;i++){
            if(s1[i]!=s2[i]) return false;
        }
        for(int i=0;i<len1;i++){
            if(s1[i]!=s2[len2-len1+i]) return false;
        }
        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        int n = words.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isPrefixAndSuffix(words[i],words[j])) ans++;
            }
        }
        return ans;
    }
};