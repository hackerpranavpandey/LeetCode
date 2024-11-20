class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> t(3,0);
        for(int i=0;i<s.size();i++){
            t[s[i]-'a']++;
        }
        for(int i=0;i<3;i++){
            if(t[i]<k)
                return -1;
        }
        vector<int> window(3, 0);
        int left = 0, maxWindow = 0;

        for (int right = 0; right < s.size(); right++) {
            window[s[right] - 'a']++;
            while (left <= right &&
                   (t[0] - window[0] < k || t[1] - window[1] < k ||
                    t[2] - window[2] < k)) {
                window[s[left] - 'a']--;
                left++;
            }

            maxWindow = max(maxWindow, right - left + 1);
        }

        return s.size() - maxWindow;
    }
};