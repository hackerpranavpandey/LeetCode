class Solution {
private:
    vector<int> solve(string s){
        vector<int> ans;
        // for(int i=0;i<s.size();i++){
        //     if(s[i]=='+' || s[i]=='-' || s[i]=='*')
        //         n_o.push_back(i);
        // }
        // // in case there is only one operator
        // if(n_o.size()==1){
        //     int num_1=s.substr(0,n_o[0]),num_2=s.substr(n_o[0]+1);
        //     if(n_o[0]=='+'){
        //         ans.push_back(num_1+num_2);
        //         return;
        //     }
        //     else if(n_[o]=='-'){
        //         ans.push_back(num_1-num_2);
        //         return;
        //     }
        //     else{
        //         ans.push_back(num_1*num_2);
        //         return;
        //     }
        // }
        for(int i=0;i<s.size();i++){
            if(s[i]=='+' || s[i]=='-' || s[i]=='*'){
                string left_part=s.substr(0,i),right_part=s.substr(i+1);
                vector<int> l=solve(left_part);
                vector<int> r=solve(right_part);
                for(int t_1:l){
                    for(int t_2:r){
                         if(s[i]=='+')
                            ans.push_back(t_1+t_2);
                        else if(s[i]=='-')
                            ans.push_back(t_1-t_2);
                        else
                            ans.push_back(t_1*t_2);
                    }
                }
            }
        }
        if(ans.size()==0)
            ans.push_back(stoi(s));
        return ans;
    }
public:
    vector<int> diffWaysToCompute(string expression) {
       return solve(expression);
    }
};