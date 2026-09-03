class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int left = 0; left < nums.size(); left++){
            if(left > 0 && nums[left] == nums[left - 1]) continue;
            int next = left + 1;
            int last = nums.size() - 1;
            while(next < last){
                int sum = nums[left] +nums[next] +nums[last];
                if(sum == 0){
                    result.push_back({nums[left], nums[next], nums[last]});
                    next ++;
                    last --;
                    while(next < last && nums[next] == nums[next - 1]) next++;
                    while(next < last && nums[last] == nums[last + 1]) last--;
                }
                else if(sum < 0){
                    next++;
                }
                else{
                    last--;
                }
            }
        }
        return result;
    }
};