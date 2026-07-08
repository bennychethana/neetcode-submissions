class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        float t = 0;
        int n = position.size();
        if(n==1) return 1;
        int ans = 0;
        vector<pair<int,float>> v;
        for(int i=0;i<n;i++){
            t = (float)(target-position[i])/speed[i];
            v.push_back({position[i],t});
        }
        sort(v.begin(),v.end());
        float prev = 0;
        for(int i=n-1;i>=0;i--){
            if(v[i].second>prev){
                ans++;
                prev = v[i].second;
            }
        }
        return ans;
    }
};


//     4 1 0 7
//     2 2 1 1

//     0 1 4 7
//     1 2 2 1
//   10 4.5 3 3

//     t = dist/speed
