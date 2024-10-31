class Solution {
private:
    long long repairDist(int rI,int fI,vector<int>& robot,vector<int>& fact,vector<vector<long long>>& dp){
        // for each robot either repair at present factory or not
        if(rI==robot.size())
            return 0;
        if(fI==fact.size())
            return 1e12;
        if(dp[rI][fI]!=-1)
            return dp[rI][fI];
        long long include=abs(robot[rI]-fact[fI])+repairDist(rI+1,fI+1,robot,fact,dp);
        long long exclude=repairDist(rI,fI+1,robot,fact,dp);
        dp[rI][fI]=min(include,exclude);
        return dp[rI][fI];
    }
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        // below is brute forace approach so that finding the minimum distance for each robot 
        // long long ans=0;
        // int n=robot.size();
        // int m=factory.size();
        // for(int i=0;i<n;i++){
        //     int dist=INT_MAX;
        //     int index=-1;
        //     for(int j=0;j<m;j++){
        //         if(factory[j][1]>0){
        //             if(abs(robot[i]-factory[j][0])<dist){
        //                 dist=abs(robot[i]-factory[j][0]);
        //                 index=j;
        //             }
        //         }
        //     }
        //     ans+=abs(robot[i]-factory[index][0]);
        //     factory[index][1]-=1;
        // }
        // return ans;
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        vector<int> factory_dist;
        for(int i=0;i<factory.size();i++){
            for(int j=0;j<factory[i][1];j++){
                factory_dist.push_back(factory[i][0]);
            }
        }
        int n=robot.size(), m=factory_dist.size();
        vector<vector<long long>> dp(n,vector<long long>(m,-1));
        long long ans=repairDist(0,0,robot,factory_dist,dp);
        return ans;
    }
};