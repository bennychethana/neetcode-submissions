class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]==']'){
                string substr = "";
                while(st.top()!='['){
                    substr+=st.top();
                    st.pop();
                } // bbba
                st.pop();
                string num = "";
                while(!st.empty() && isdigit(st.top())){
                    num+=st.top();
                    st.pop();
                } // bbba
                reverse(num.begin(),num.end());
                int m = stoi(num);// number
                while(m--){
                    for(int j=substr.size()-1;j>=0;j--){
                        st.push(substr[j]);
                    }
                }
            }
            else{
                st.push(s[i]);
            }
        }
        string ans = "";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};