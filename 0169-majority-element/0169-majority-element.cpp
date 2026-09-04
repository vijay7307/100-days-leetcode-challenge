class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int x : nums){
            mp[x]++;
        }
        for(pair x : mp){
            if(mp[x.first] > n/2) return x.first;
        }
        return -1;
    }
};