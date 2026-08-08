class Solution {
public:
    int n = 0;
    bool is_valid(string seg){
        int seg_num = 0;
        if(seg[0]=='0' && seg.size()!=1) return false;
        for(int i=0;i<seg.size();i++){
            if(!isdigit(seg[i])) return false;
        }
        seg_num = stoi(seg);
        if(seg_num>=0 && seg_num<=255) return true;
        return false;
    }
    vector<string> ans;
    // decision : choose next valid segment
    void f(int start_ind, string& s, string& cur_path, int parts){ // state : start_ind, parts
        // base case/goal
        if(start_ind==n && parts==4){
            cur_path.pop_back();
            ans.push_back(cur_path);
            return;
        }
        // choices from state : valid forward segments of len 1,2,3
        for(int len = 1;len<=3;len++){
            if (start_ind + len > n) break;
            string seg = s.substr(start_ind,len);
            if(is_valid(seg)){
                int old_size = cur_path.size();
                cur_path+=seg;
                cur_path+='.';
                parts++;
                f(start_ind+len,s,cur_path,parts);
                parts--;
                cur_path.resize(old_size); // undo
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        n = s.size();
        string cur_path = "";
        f(0,s,cur_path,0);
        return ans;
    }
};