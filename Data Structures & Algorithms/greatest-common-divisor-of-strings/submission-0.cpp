class Solution {
public:
    bool check(string s, int n, string str1, string str2){
        if(str1.size()%n!=0) return false;
        if(str2.size()%n!=0) return false;
        bool is_str1_fit = false;
        bool is_str2_fit = false;
        string s1 = "";
        while(s1.size()<str1.size()){
            s1+=s;
            if(s1==str1){
                is_str1_fit = true;
                break;
            }
        }
        string s2 = "";
        while(s2.size()<str2.size()){
            s2+=s;
            if(s2==str2){
                is_str2_fit = true;
                break;
            }
        }
        return is_str1_fit && is_str2_fit;
    }
    string gcdOfStrings(string str1, string str2) {
        int len1 = str1.size();
        int len2 = str2.size();
        int l = min(len1,len2);
        string small_s = len1<=len2 ? str1 : str2;
        string ans = "";
        for(int i=1;i<=l;i++){
            string s = small_s.substr(0,i);
            if(check(s,i,str1,str2)){
                ans = s;
            }
        }
        return ans;
    }
};