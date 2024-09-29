class AllOne {
public:
    // simple it is easy to do in O(n) for get min or max or O(logn) but not O(1)
    // so use two map now
    unordered_map<string,int> count;
    map<int,unordered_set<string>> freq;
    // one for the freq count and another the corresponding string
    // int min_count=INT_MAX,max_count=INT_MIN;
    // string min_freq="",max_freq="";
    AllOne() {
        
    }
    
    void inc(string key) {
        int t=count[key];
        count[key]++;
        if(t>0)
            freq[t].erase(key);
        freq[t+1].insert(key);
        if(freq[t].empty())
            freq.erase(t);
    }
    
    void dec(string key) {
        int t=count[key];
        count[key]--;
        freq[t].erase(key);
        if(count[key]==0)
            count.erase(key);
        else
            freq[t-1].insert(key);
        if(freq[t].empty())
            freq.erase(t);
    }
    
    string getMaxKey() {
        if(count.empty())
            return "";
        // iterator to retun from end set to any string
        return *(freq.rbegin()->second.begin());
    }
    
    string getMinKey() {
        if(count.empty())
            return "";
        // return string from least freq set
        return *(freq.begin()->second.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */