class Solution {
public:
    vector<vector<int>> memo;
    bool matching(string& s, string& p, int i, int j){
        // base case
        if (j == p.size()) {
            return i == s.size();
        }
        // action
        // if next char is * : use * , dont use *
        bool cur_char_match = i<s.size() && (s[i]==p[j] || p[j]=='.');
        bool is_next_char_star = j+1<p.size() && p[j+1]=='*';
        bool use_star = false;
        bool skip_star = false;
        if(memo[i][j]!=-1) return memo[i][j];
        bool ans = false;
        if(is_next_char_star){
            skip_star = matching(s,p,i,j+2);
            if(cur_char_match){
                use_star = matching(s,p,i+1,j);
                ans = use_star || skip_star;
            }
            else{
                ans = skip_star;
            }
        }
        else if(!is_next_char_star && cur_char_match){
            ans = matching(s,p,i+1,j+1);
        }
        else ans = false;
        memo[i][j] = ans;
        return ans;
    }
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        memo = vector<vector<int>>(m+1,vector<int>(n+1,-1));
        return matching(s,p,0,0);
    }
};
