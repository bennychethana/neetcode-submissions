class Solution {
public:
    int scoreOfString(string s) {
        int ans = 0;
        int n = s.size();
        for(int i=1;i<n;i++){
            int a = s[i-1];
            int b = s[i];
            ans+= abs(a-b);
        }
        return ans;
    }
};