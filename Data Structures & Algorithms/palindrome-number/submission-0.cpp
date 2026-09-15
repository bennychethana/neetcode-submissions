class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int num1 = x;
        int num2 = 0;
        int n = 0;
        while(x){
            n++;
            x = x/10;
        }
        x = num1;
        int i = 0;
        while(num1){
            int digit = num1%10;
            num1 = num1/10;
            num2 = num2*10 + digit;
        }
        return x==num2;
    }
};

// 123