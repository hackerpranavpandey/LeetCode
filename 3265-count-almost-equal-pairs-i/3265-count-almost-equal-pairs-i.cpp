class Solution {
public:
    int countPairs(vector<int>& nums) {
        // use string first convert each of the number to string
        int ans=0;
        for(int i=0;i<nums.size();i++){
            string t_1=to_string(nums[i]);
            for(int j=i+1;j<nums.size();j++){
                string t_2=to_string(nums[j]);
                // for the case leading zeros
                // just make both of the string size same by adding 0 at start
                while(t_1.size()>t_2.size()){
                    t_2='0'+t_2;
                }
                while(t_2.size()>t_1.size()){
                    t_1='0'+t_1;
                }
                // now iterate the digits of the number 
                // keep track of index where it is different
                string diff_index="";
                for(int k=0;k<t_1.size();k++){
                    if(t_1[k]!=t_2[k]){
                        diff_index+=to_string(k);
                    }
                }
                // if no difference continue by adding 1 to ans
                if(diff_index.size()==0){
                    ans++;
                    continue;
                }
                // if difference is exactly 2 check if swapped value
                else if(diff_index.size()==2){
                    int i_1=stoi(diff_index.substr(0,1));
                    int i_2=stoi(diff_index.substr(1,1));
                    if(t_2[i_1]==t_1[i_2] && t_2[i_2]==t_1[i_1])
                        ans++;
                }
            }
        }
        return ans;
    }
};