class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        int sum = 0;
        while(true){
            sum = 0;
            while(n){
                sum+=(n%10)*(n%10);
                n/=10;
            }
            if(set.count(sum)) return false;
            if(sum==1) return true;
            set.insert(sum);
            n = sum;
        }
        return false;
    }
};
