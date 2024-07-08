class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> circular_queue;
       for(int i=1;i<=n;i++){
            circular_queue.push_back(i);
        }
        int remove=0;
        int j=0;
        while(remove!=(n-1)){
            int step=0;
            while(step!=k){
                 if(circular_queue[j]!=-1)
                    step++;
                 if(step<k)
                     j=(j+1)%n;
            }
            circular_queue[j]=-1;
            remove++;
        }
        int ans=-1;
        for(int i=0;i<n;i++){
            if(circular_queue[i]!=-1){
                ans=circular_queue[i];
                break;
            }
        }
        return ans;
    }
};