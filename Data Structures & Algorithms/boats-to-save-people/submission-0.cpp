class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(),people.end());
        int ans = 0;
        int l = 0;
        int r = n-1;
        while(l<=r){
            if(people[l]+people[r]<=limit){
                ans++;
                l++;
                r--;
            }
            else if(people[l]+people[r]>limit){
                ans++;
                r--;
            }
        }
        return ans;
    }
};

// 1 2 2 3 3

// 1 2 4 5