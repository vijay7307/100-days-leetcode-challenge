class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, int> mp;
        unordered_map<char, int> mp2;
        for(auto x : s){
            mp[x]++;
        }
        for(auto y : t){
            if(mp.count(y) == 0) return false;
            mp2[y]++;
        }
        for(auto it : mp){
            if(mp[it.first] != mp2[it.first]) return false;
        }
        return true;
        
    }
};