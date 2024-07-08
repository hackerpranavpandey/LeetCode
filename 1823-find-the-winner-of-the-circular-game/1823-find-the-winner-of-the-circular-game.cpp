class Solution {
public:
    int findTheWinner(int n, int k) {
        // insert all into vector
       vector<int> circular_queue;
       for(int i=1;i<=n;i++){
            circular_queue.push_back(i);
        }
        int remove=0;
        int j=0;
        // continue till n-1 are removes
        while(remove!=(n-1)){
            // step will tell k numbers covered
            int step=0;
            while(step!=k){
                // count only if not equals -1
                 if(circular_queue[j]!=-1)
                    step++;
                 if(step<k)
                     j=(j+1)%n;
            }
            // make it -1 now considering it removed
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