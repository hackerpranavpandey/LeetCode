class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_buy=INT_MAX;
        int max_buy=INT_MIN;
        int ans=0;
        for(int price:prices){
            min_buy=min(min_buy,price);
            ans=max(ans,(price-min_buy));
        }
        return ans;
    }
};