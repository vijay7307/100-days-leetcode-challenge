class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>  result;
        unordered_map<int, int> mp;
        int value = 0;
        for(int i = 0; i < nums.size(); i++){
            value = target - nums[i];
            if(mp.count(value)){
                result.push_back(mp[value]);
                result.push_back(i);
                return result;
            }
            mp[nums[i]] = i;
        }
        return result;
    }
};