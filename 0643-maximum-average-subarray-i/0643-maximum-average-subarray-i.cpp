class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left = 0;
        int sum = 0;
        for(int i = 0; i < k; i++){
            sum += nums[i];
        }
        double maxsum = sum;
        for(int right = k; right < nums.size(); right++){
            sum = sum - nums[left] + nums[right];
            maxsum = max(maxsum, double(sum));
            left++;
        }
        return double(maxsum/k);
    }
};