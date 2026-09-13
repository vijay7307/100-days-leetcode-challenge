class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int freq[26] = {0};
        int windowFreq[26] = {0};
        vector<int> result;

        for(int i = 0; i < p.size(); i++){
            freq[p[i] - 'a']++;
        }

        int left = 0;
        for(int right = 0; right < s.size(); right++){
            windowFreq[s[right] - 'a']++ ; 

            if(right - left + 1 > p.size()){
                windowFreq[s[left] - 'a']--;
                left++;
            }
            
            if(right - left +  1 == p.size()){

                bool same = true;
                for(int i = 0; i < 26; i++){
                    if(freq[i] != windowFreq[i]){
                        same = false;
                        break;
                    };
                }

                if(same){
                    result.push_back(left);
                }
            }
        }
        return result;
    }
};