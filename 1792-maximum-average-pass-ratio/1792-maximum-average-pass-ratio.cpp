class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // int n=classes.size();
        // double ans=0;
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> store; 
        // for(vector<int>& classe:classes){
        //     int pass=classe[0];
        //     int students=classe[1];
        //     if(pass==students)
        //         ans+=1;
        //     else
        //         store.push({students,pass});
        // }
        // while(extraStudents){
        //     pair<int,int> t=store.top();
        //     store.pop();
        //     t.first++;
        //     t.second++;
        //     store.push(t);
        //     extraStudents--;
        // }
        // while(!store.empty()){
        //     pair<int,int> t=store.top();
        //     store.pop();
        //     ans+=((double)(t.second)/(double)(t.first));
        // }
        // return ans/n;
        // above approach is not correct so what if keep the information of maximum gain in the ratio already
        // simple just think what if extrastudent is added to that class already and then use max heap
        priority_queue<pair<double,vector<int>>> store; 
        for(vector<int>& classe:classes){
            double gain=(double)(classe[0]+1)/(classe[1]+1) - (double)(classe[0])/(classe[1]);
            store.push({gain,classe});
        }
        while(extraStudents){
            pair<double,vector<int>> t=store.top();
            store.pop();
            t.second[0]+=1;
            t.second[1]+=1;
            t.first=(double)(t.second[0]+1)/(t.second[1]+1) - (double)(t.second[0])/(t.second[1]);
            store.push(t);
            extraStudents--;
        }
        int n=classes.size();
        double ans=0;
        while(!store.empty()){
            pair<double,vector<int>> t=store.top();
            store.pop();
            ans+=(double)(t.second[0])/(double)(t.second[1]);
        }
        return ans/n;
    }
};