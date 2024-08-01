class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans=0;
        for(auto s:details){
            string t=s.substr(11,2);  // starting index, number of positions not just end index
            int age=stoi(t);
            if(age>60)
                ans++;
        }
        return ans;
    }
};