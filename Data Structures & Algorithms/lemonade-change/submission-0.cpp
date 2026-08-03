class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cur_change_5 = 0;
        int cur_change_10 = 0;
        for(int i=0;i<bills.size();i++){
            cout<<i<<endl;
            if(i==0 && bills[i]>5) return false;
            if(bills[i]==5){
                cur_change_5++;
            }
            else if(bills[i]==10){
                if(cur_change_5<1) return false;
                cur_change_5--;
                cur_change_10++;
            }
            else{
                if (cur_change_5>=1 && cur_change_10>=1){
                    cur_change_5--;
                    cur_change_10--;
                }
                else if(cur_change_5>=3){
                    cur_change_5-=3;
                }
                else return false;
            }
        }
        return true;
    }
};