class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        unordered_set<char> st;
        int longestLength = 0;
        if(s.size() == 0) return 0;
        for(int right = 0; right < s.size(); right++){
            while(st.count(s[right])){
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            longestLength = max(longestLength, int(st.size()));
        }
        return longestLength;
    }
};