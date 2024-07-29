class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans=0;
        int n=rating.size();
        // for(int i=0;i<n-2;i++){
        //     for(int j=i+1;j<n-1;j++){
        //         for(int k=j+1;k<n;k++){
        //             if(rating[i]>rating[j] && rating[j]>rating[k])
        //                 ans+=1;
        //             else if(rating[i]<rating[j] && rating[j]<rating[k])
        //                 ans+=1;
        //         }
        //     }
        // }
        // return ans;
        // above solution is true but is brute force approach to solve this problem
        // since all values are unique
        // what we can do is to consider each soldier as middle one and find smaller value to its left and larger values to it right
        // jaise agra 2 3 4 5 6 hai tab jaise 4 ko select kiya s mid index value tab uske left me jao aur sare chote value nikalo
        // right me jao aur sare bade value nikalo
        // phir dono ko multiply kar do
        // but ye case hua ascending ka
        // descending me ulta karo
        for(int mid=0;mid<n;mid++){
            int left_small=0;
            int right_large=0;
            for(int small=mid-1;small>=0;small--){
                if(rating[small]<rating[mid])
                    left_small++;
            }
            for(int large=mid+1;large<n;large++){
                if(rating[large]>rating[mid])
                    right_large++;
            }
            ans+=left_small*right_large;
            // for descending
            ans+=(mid-left_small)*(n-mid-right_large-1);
        }
        return ans;
    }
};