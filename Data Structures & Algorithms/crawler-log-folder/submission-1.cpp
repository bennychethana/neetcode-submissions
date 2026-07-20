class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n = logs.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(logs[i]=="./") continue;
            else if(logs[i]=="../"){
                if(cnt==0) continue;
                cnt--;
            }
            else{
                cnt++;
            }
        }
        return cnt<0 ? 0 : cnt;
    }
};