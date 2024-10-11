class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        // int arrivaltargetFriend=times[targetFriend][0];
        // sort(times.begin(),times.end());
        // priority_queue<int,vector<int>,greater<int>> vacant;
        // unordered_map<int,int> chairIndex;
        // int ans=0,n=times.size();
        // for(int i=0;i<n;i++){
        //     int chair=i;
        //     for(auto it=chairIndex.begin();it!=chairIndex.end();){
        //         // if the departure time of occupied chair is less than that of the present arrival
        //         if(times[it->first][1]<=times[i][0]){
        //             vacant.push(it->second);
        //             it=chairIndex.erase(it);
        //         }
        //         else{
        //             it++;
        //         }
        //     }
        //     if(!vacant.empty())
        //         chair=vacant.top(),vacant.pop();
        //     if(times[i][0]==arrivaltargetFriend){
        //         ans=chair;
        //         break;
        //     }
        //     chairIndex[i]=chair;
        // }
        // return ans;
        // lets try brute force approach first
        int targetArrival=times[targetFriend][0];
        sort(times.begin(),times.end());
        int n=times.size();
        vector<int> chairIndex(n,0);  // isme har index ke liye kab tak chair booked hai ye rahega
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                if(chairIndex[j]<=times[i][0]){
                     chairIndex[j]=times[i][1];
                     if(times[i][0]==targetArrival)
                        return j;
                      break;   
                }
            }
        }
        return 0;
    }
};