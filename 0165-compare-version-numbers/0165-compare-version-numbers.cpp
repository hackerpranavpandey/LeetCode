class Solution {
public:
    int compareVersion(string version1, string version2) {
        int start_1=0,start_2=0;
        int end_1=0,end_2=0;
        int n=version1.size(),m=version2.size();
        while(end_1<n || end_2<m){
            while(end_1<n && version1[end_1]!='.'){
                    end_1++;}
            while(end_2<m && version2[end_2]!='.'){
                    end_2++;}
            string t_1="",t_2="";
            if(start_1<n)
                t_1=version1.substr(start_1,end_1-start_1);
            if(start_2<m)
                t_2=version2.substr(start_2,end_2-start_2);
            int num_1=0,num_2=0;
            if(t_1.size()!=0)
                num_1=stoi(t_1);
            if(t_2.size()!=0)
                num_2=stoi(t_2);
            if(num_1>num_2)
                return 1;
            else if(num_1<num_2)
                return -1;
            end_1++,end_2++;
            start_1=end_1,start_2=end_2;
        }
        return 0;
    }
};