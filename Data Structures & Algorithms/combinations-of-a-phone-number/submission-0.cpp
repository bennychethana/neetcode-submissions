class Solution {
public:
    vector<string> ans;
    unordered_map<char, string> mp = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    int n = 0;
    void f(int digit_index, string cur_path,string digits){
        // base case
        if(cur_path.size()==n){
            ans.push_back(cur_path);
            return;
        }
        // action/choices
        for (char c : mp[digits[digit_index]]) {
            cur_path.push_back(c);

            f(digit_index + 1, cur_path, digits);

            cur_path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        n = digits.size();
        string cur_path = "";
        f(0,cur_path, digits);
        return ans;
    }
};
