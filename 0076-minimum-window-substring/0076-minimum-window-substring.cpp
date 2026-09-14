class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(m < n) return "";
        unordered_map<char, int> mp;
        int count = 0;
        int st = -1;
        int minLength = INT_MAX;
        int left = 0;
        for(char x : t){
            mp[x]++;
        }
        for(int right = 0; right < m; right++){

            if(mp[s[right]] > 0){
                count++;
            }

            mp[s[right]]--;

            while(count == n){
                if(right - left + 1  < minLength){
                    minLength = right - left + 1;
                    st = left;
                }
                mp[s[left]]++;
                if(mp[s[left]] > 0){
                    count--;
                } 
                left++;
            }
            
        }
        return st == -1 ? "" : s.substr(st, minLength);
    }
};