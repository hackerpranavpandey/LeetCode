class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int count=0;
        for(int num:nums){
            if(num==0)
                count++;
        }
        if(count==nums.size())
            return "0";
        vector<pair<int,int>> digits;
        for(int num:nums){
            int curr=num;
            if(curr==0)
                digits.push_back({0,0});
            while(num>0){
                int d=num%10;
                num/=10;
                if(num==0)
                    digits.push_back({d,curr});
            }
        }
        sort(digits.begin(),digits.end(),[](pair<int,int> a,pair<int,int> b){
            if(a.first>b.first)
                return true;
            else if(a.first==b.first)
            return to_string(a.second)+to_string(b.second)>to_string(b.second)+to_string(a.second);
            else
                return false;
        });
        string ans="";
        for(auto it:digits){
            ans+=to_string(it.second);
        }
        return ans;
    }
};