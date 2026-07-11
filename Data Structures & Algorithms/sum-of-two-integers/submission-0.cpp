class Solution {
public:
    int getSum(int a, int b) {
        int c = 0;
        int sum = 0;
        int carry = 0;
        int a_lastbit = a&1;
        int b_lastbit = b&1;
        a = a>>1;
        b = b>>1;
        sum = a_lastbit^b_lastbit;
        carry = a_lastbit&b_lastbit;
        c = c|sum;
        for(int i=1;i<32;i++){
            a_lastbit = a&1;
            b_lastbit = b&1;
            sum = a_lastbit^b_lastbit^carry;
            carry = (a_lastbit & b_lastbit) | (a_lastbit & carry) | (b_lastbit & carry);
            a = a>>1;
            b = b>>1;
            c = c|(sum<<i);
        }
        return c;
    }
};

// 1 = 0001
// 1 = 0001
//   = 0010

// 4 = 0100
// 7 = 0111
//   = 1011