class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int l = 0;
        int r = n-1;
        while(s[l]==' ' || !isalnum(s[l])) l++;
        while(s[r]==' ' || !isalnum(s[r])) r--;
        while(l<r){
            if(tolower(s[l])!=tolower(s[r])){
                return false;
            }
            l++;
            r--;
            while(l<r && (s[l]==' '  || !isalnum(s[l]))) l++;
            while(l<r && (s[r]==' '  || !isalnum(s[r]))) r--;
        }
        return true;
    }
};
