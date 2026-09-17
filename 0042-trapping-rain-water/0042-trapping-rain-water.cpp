class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int water = 0;
        while(j > i){
            if(height[i] <= height[j]){
                int k = i + 1;
                while(height[k] <= height[i] && k < j){
                    water += height[i] - height[k];
                    k++;
                }
                i = k;
            }
            else{
                int l = j - 1;
                while(height[l] <= height[j] && l > i){
                    water += height[j] - height[l];
                    l--;
                }
                j = l;
            }
        }
        return water;
    }
};