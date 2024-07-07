class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=numBottles;
        while(numBottles>=numExchange){
            int bottle=numBottles/numExchange;
            ans+=bottle;
            numBottles=bottle+(numBottles%numExchange);
        }
        return ans;
    }
};