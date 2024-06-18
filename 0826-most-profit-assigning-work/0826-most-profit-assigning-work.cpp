class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int ans=0;
        for(int i=0;i<worker.size();i++){
            int work=worker[i];
            int max_profit=0;
            for(int j=0;j<difficulty.size();j++){
                if(difficulty[j]<=work){
                    max_profit=max(max_profit,profit[j]);
                }
            }
            ans+=max_profit;
        }
        return ans;
    }
};