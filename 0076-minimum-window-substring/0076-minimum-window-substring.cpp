class Solution {
public:
    string minWindow(string s, string t) {
        int hash[128] = {0};
        int minlength = INT_MAX;
        int stIdx = -1;
        int count = 0;
        int left = 0;
        for(auto x : t) hash[x]++;
        for(int right = 0; right < s.size(); right++){
            if(hash[s[right]] > 0){
                count++;
            }
            hash[s[right]]--;
            while(count == t.size()){
                if(right-left+1 < minlength){
                    minlength = right-left+1;
                    stIdx = left;
                }
                hash[s[left]]++;
                if(hash[s[left]] > 0){
                    // stIdx = left;
                    count--;
                }
                left++;
            }
        }
        return stIdx == -1 ? "" : s.substr(stIdx, minlength);
    }
};