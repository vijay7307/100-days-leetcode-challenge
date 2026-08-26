class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int left = 0; left < nums.size(); left++){
            if(left > 0 && nums[left] == nums[left - 1] ) continue;
            int sum = 0;
            int next = left + 1;
            int right = nums.size() - 1; 
            while(next < right){
                sum = nums[left] + nums[right] + nums[next];
                if(sum > 0) right -- ;
                else if(sum < 0) next++;
                else {
                    res.push_back({nums[left], nums[next], nums[right]});
                    next++;
                    right--;  
                    while(next < right && nums[next] == nums[next - 1]){
                        next++;
                    }
                    while(next < right && nums[right] == nums[right + 1]){
                        right--;
                    }  
                }
                
            }
        }
        return res;
    }
};