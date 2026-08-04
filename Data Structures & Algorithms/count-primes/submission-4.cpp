class Solution {
public:
    // bool is_prime(int n){
    //     if (n < 2) return false;
    //     for(int i=2;i*i<=n;i++){
    //         if(n%i==0) return false;
    //     }
    //     return true;
    // }
    int countPrimes(int n) {
        // int ans = 0;
        // for(int i=2;i<n;i++){
        //     if(is_prime(i)){
        //         ans++;
        //     }
        // }
        // return ans;
        if(n<2) return 0;
        vector<bool> is_prime(n,true);
        is_prime[0] = false;
        is_prime[1] = false;
        for(int i=2;i*i<n;i++){
            // if number is prime, mark multiples starting at i*i as true
            if (is_prime[i]){
                for(int j=i*i;j<n;j=j+i){
                    is_prime[j] = false;
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(is_prime[i]) ans++;
        }
        return ans;
    }
};