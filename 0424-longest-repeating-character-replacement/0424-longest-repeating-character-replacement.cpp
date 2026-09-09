class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int left = 0;
        int maxlength = 0;
        int maxfreq = 0;
        for(int right = 0; right < s.size(); right++){
            mp[s[right]]++; 
            maxfreq = max(maxfreq, mp[s[right]]);
            int length = right - left + 1;
            if(length - maxfreq <= k){
                maxlength = max(maxlength, length);
            }else{
                mp[s[left]]--;
                left++ ;
            }
        }
        return maxlength;
    }
};