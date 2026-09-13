class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int freq1[26] = {0};
        int freq2[26] = {0};
        for (int i = 0; i < s1.size(); i++) {
            freq1[s1[i] - 'a']++;
        }
        int left = 0;
        for (int right = 0; right < s2.size(); right++) {
            freq2[s2[right] - 'a']++;
            int windowSize = right - left + 1;
            if (windowSize > s1.size()) {
                freq2[s2[left] - 'a']--;
                left++;
            }

            if (right - left + 1 == s1.size()) {

                bool same = true;

                for (int i = 0; i < 26; i++) {
                    if (freq1[i] != freq2[i]) {
                        same = false;
                        break;
                    }
                }

                if (same) return true;
            }
            
        }
        return false;
    }
};