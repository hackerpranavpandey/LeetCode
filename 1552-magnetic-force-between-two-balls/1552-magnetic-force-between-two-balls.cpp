class Solution {
    // ye function batega ki kitne ball hai jinke beech ka magnetic force gap hai
private:
    int number_of_balls(vector<int>& position,int gap){
        // pehle ball hmesha hoga hi
        int current=position[0];
        int n_p=1;
        for(int i=1;i<position.size();i++){
    // agar gap ya jyada magnetic force hai tab current position ko update karo aur n_p ko increase karo
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
        // wo minimum gap nukalo jisme m balls rakh sako
        // binary seach lagate hai 
        sort(position.begin(),position.end());
        int ans=0;
        int start=1; 
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