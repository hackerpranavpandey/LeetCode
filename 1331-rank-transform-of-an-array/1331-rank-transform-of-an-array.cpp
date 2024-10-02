class Solution {
// private:
//     int hcf(int n1,int n2){
//         if(n2==0)
//             return n1;
//         return hcf(n2,n1%n2);
//     }
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // the logic of hcf is not correct it is simple sorting
        if(arr.size()==0)
            return arr;
        else if(arr.size()==1)
            return {1};
        // int t_1=max(arr[0],arr[1]),t_2=min(arr[0],arr[1]);
        // int rank=hcf(t_1,t_2);
        // if(rank==1)
        //     return arr;
        // for(int i=2;i<arr.size();i++){
        //     t_1=max(rank,arr[i]),t_2=min(rank,arr[i]);
        //     rank=hcf(t_1,t_2);
        // }
        // for(int i=0;i<arr.size();i++){
        //     arr[i]/=rank;
        // }
        // return arr;
        vector<pair<int,int>> arr_2;
        for(int i=0;i<arr.size();i++){
            arr_2.push_back({arr[i],i});
        }
        sort(arr_2.begin(),arr_2.end());
        arr[arr_2[0].second]=1;
        for(int i=1;i<arr.size();i++){
            if(arr_2[i].first==arr_2[i-1].first)
                arr[arr_2[i].second]=arr[arr_2[i-1].second];
            else
                arr[arr_2[i].second]=arr[arr_2[i-1].second]+1;
        }
        return arr;
    }
};