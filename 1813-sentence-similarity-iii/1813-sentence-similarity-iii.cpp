class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        // these two vectors will store the words of both sentence resp
        vector<string> v_1,v_2;
        int n=sentence1.size(),m=sentence2.size();
        int i=0;
        string s_1="";
        while(i<n){
            if(sentence1[i]!=' ')
                s_1+=sentence1[i];
            else
                v_1.push_back(s_1),s_1="";
            i++;
        }
        if(s_1!=""){
            v_1.push_back(s_1);
        }
        s_1="";
        i=0;
        while(i<m){
            if(sentence2[i]!=' ')
                s_1+=sentence2[i];
             else
                v_2.push_back(s_1),s_1="";
            i++;
        }
        if(s_1!=""){
            v_2.push_back(s_1);
        }
        // common prefix finding
        int t_1=v_1.size(),t_2=v_2.size();
        string prefix="";
        unordered_set<int> set_1,set_2;
        for(int i=0;i<min(t_1,t_2);i++){
            if(v_1[i]==v_2[i]){
                if(prefix!="")
                    set_2.emplace(i),set_2.emplace(i),prefix+=(" "+v_1[i]);
                else
                    set_1.emplace(i),set_2.emplace(i),prefix=v_1[i];
            }
            else
                break;
        }
        // common suffix finding 
        string suffix="";
        for(int i=0;i<min(t_1,t_2);i++){
            if(v_1[t_1-i-1]==v_2[t_2-i-1] && !set_1.count(t_1-i-1) && !set_2.count(t_2-i-1)){
                if(suffix=="")
                    suffix=v_1[t_1-1-i];
                else  
                    suffix=v_1[t_1-1-i]+" "+suffix;
            }
            else
                break;
        }
        if(prefix=="" && suffix=="")
            return false;
        else if(prefix=="")
            return (suffix==sentence1 || suffix==sentence2);
        else if(suffix=="")
            return (prefix==sentence1 || prefix==sentence2);
        else
            return ((prefix+" "+suffix)==sentence1 || (prefix+" "+suffix)==sentence2);
    }
};