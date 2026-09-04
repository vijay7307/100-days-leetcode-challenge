class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_set<int> st1;
        unordered_set<int> st2;
        for(int x : nums1){
            st1.insert(x);
        }
        for(int x : nums2){
            st2.insert(x);
        }
        for(auto x : st1){
            if(st1.count(x) == st2.count(x)) result.push_back(x);
        }
        return result;
    }
};