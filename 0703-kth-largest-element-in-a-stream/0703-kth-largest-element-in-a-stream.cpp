class KthLargest {
public:
    int k;
    vector<int> store_nums;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int num:nums){
            store_nums.push_back(num);
        }
        sort(store_nums.begin(),store_nums.end());
    }
    
    int add(int val) {
        // lets apply binary search since it is sorted
        int left=0;
        int right=store_nums.size()-1;
        int ans=-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(store_nums[mid]==val){
                ans=mid;
                break;
            }
            if(store_nums[mid]<val)
                left=mid+1;
            else
                right=mid-1;
        }
        if(ans==-1)
            ans=left;
        store_nums.insert(store_nums.begin()+ans,val);
        return store_nums[store_nums.size()-k];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */