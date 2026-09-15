class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxwater = 0;
        int st = 0;
        int end = height.size() - 1;
        while(st < end){
            int area = (end - st)*min(height[end], height[st]);
            if(height[st] >= height[end]){
                end--;
            }else st++;
            maxwater = max(area, maxwater);
        }
        return maxwater;
    }
};