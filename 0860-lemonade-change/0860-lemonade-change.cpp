class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if(bills[0]!=5)
            return false;
        int coin_5=0,coin_10=0,coin_20=0;
        for(auto bill:bills){
            if(bill==5)
                coin_5+=1;
            else if(bill==10){
                if(coin_5==0)
                    return false;
                coin_10+=1,coin_5--;
            }
            else{
                if(coin_5==0 || (coin_5*5+coin_10*10)<15)
                    return false;
                coin_20++;
                if(coin_10!=0){
                    coin_10--,coin_5--;
                }
                else
                    coin_5-=3;
            }
        }
        return true;
    }
};