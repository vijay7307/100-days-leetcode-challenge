class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int min = 1;
        int max = *max_element(piles.begin(), piles.end());
        while(min < max){
            int mid = min + (max - min)/2;
            int hour = 0;
            for(int i = 0; i < piles.size(); i++){
                hour += (piles[i] + mid - 1)/mid;
            }
            if(hour <= h) max = mid;
            else min = mid + 1;
        }
        return min;
    }
};