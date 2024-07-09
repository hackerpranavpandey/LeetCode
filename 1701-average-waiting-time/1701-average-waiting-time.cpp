class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int start_time=0;
        int n=customers.size();
        double ans=0;
        for(int i=0;i<n;i++){
            start_time=max(start_time,customers[i][0]);
            int time_wait=(start_time+customers[i][1])-customers[i][0];
            ans+=time_wait;
            start_time+=customers[i][1];
        }
        ans/=n;
        return ans;
    }
};