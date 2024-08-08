class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp;
        int i_1=0;
        int i_2=0;
        while(i_1<m && i_2<n){
            if(nums1[i_1]<=nums2[i_2]){
                temp.push_back(nums1[i_1]);
                i_1++;
            }
            else{
                temp.push_back(nums2[i_2]);
                i_2++;
            }
        }
        while(i_1<m){
            temp.push_back(nums1[i_1]);
            i_1++;
        }
        while(i_2<n){
            temp.push_back(nums2[i_2]);
            i_2++;
        }
        for(int i=0;i<temp.size();i++){
            nums1[i]=temp[i];
        }
    }
};