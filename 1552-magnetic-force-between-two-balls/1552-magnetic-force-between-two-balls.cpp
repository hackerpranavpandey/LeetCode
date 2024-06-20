class Solution {
private:
    int number_of_balls(vector<int> position,int gap){
        int n_p=1;
        int current=position[0];
        for(int i=1;i<position.size();i++){
            if(position[i]-current >= gap){
                n_p+=1;
                current=position[i];
            }
        }
        return n_p;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        sort(position.begin(),position.end());
        int ans=0;
        int start=0;
        int end=position[n-1]/(m-1);
        while(start<=end){
            int mid=(start+end)/2;
            if(number_of_balls(position,mid)>=m){
                ans=mid;
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
    }
};