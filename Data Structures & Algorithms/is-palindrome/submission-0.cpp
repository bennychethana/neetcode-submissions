class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int l = 0;
        int r = n-1;
        while(l<r){
            while(!isalnum(s[l])) l++;
            while(!isalnum(s[r])) r--;
            if(l>=r) return true;
            if(tolower(s[l])==tolower(s[r])){
                l++;
                r--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
