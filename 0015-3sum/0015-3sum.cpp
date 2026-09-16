class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int st = 0;
        for(int st = 0; st < nums.size(); st++){
            if(st > 0 && nums[st] == nums[st - 1]) continue;
            int left = st + 1;
            int right = nums.size() - 1;
            while(left < right){
                int sum = nums[st] + nums[left] + nums[right];
                if(sum < 0) left++;
                else if(sum > 0) right--;
                else {
                    result.push_back({nums[st], nums[left], nums[right]});
                    left++;
                    right--;
                    while(left < right && nums[left] == nums[left - 1]){
                        left++;
                    }
                    while(left < right && nums[right] == nums[right + 1]){
                        right--;
                    }
                }
                
            }
        }
        return result;
        
    }
};