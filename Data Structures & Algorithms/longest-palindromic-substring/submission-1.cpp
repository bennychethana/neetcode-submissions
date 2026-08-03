class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int l = 0;
        int r = 0;
        int max_len = 0;
        int start = 0;
        for(int i=0;i<n;i++){
            // odd length
            l = i;
            r = i;
            while(l>=0 && r<=n-1 && s[l]==s[r]){
                if(r-l+1>max_len){
                    max_len = r-l+1;
                    start = l;
                }
                l--;
                r++;
            }
            // even length
            l = i-1;
            r = i;
            while(l>=0 && r<=n-1 && s[l]==s[r]){
                if(r-l+1>max_len){
                    max_len = r-l+1;
                    start = l;
                }
                l--;
                r++;
            }
        }
        return s.substr(start,max_len);
    }
};
