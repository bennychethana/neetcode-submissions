class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        string s = "";
        bool last_char_slash = false;
        path+='/';
        for(int i=0;i<path.size();i++){
            if(i==0 && path[i]=='/'){
                last_char_slash = true;
                continue;
            }
            if(last_char_slash && path[i]=='/') continue;
            if(path[i]=='/'){
                if(s==".." && v.size()>=1) v.pop_back();
                else if(s!="." && s!="..") v.push_back(s);
                s = "";
                last_char_slash = true;
            }
            else{
                s+=path[i];
                last_char_slash = false;
            }
        }
        string ans = "/";
        for(int i=0;i<v.size();i++){
            if(i==v.size()-1) ans+=v[i];
            else ans+=v[i]+'/';
        }
        return ans;
    }
};

