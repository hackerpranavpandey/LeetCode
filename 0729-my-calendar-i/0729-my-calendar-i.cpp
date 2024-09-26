class MyCalendar {
public:
    vector<pair<int,int>> v;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        int cnt=0;
        for(auto it:v){
            if(start>=it.second || end<=it.first)
                cnt++;
        }
        if(cnt==v.size()){
            v.push_back({start,end});
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */