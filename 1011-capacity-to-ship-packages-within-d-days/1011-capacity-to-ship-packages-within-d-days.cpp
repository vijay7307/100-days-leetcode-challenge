class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int mincap = *max_element(weights.begin(), weights.end());
        int maxcap = reduce(weights.begin(), weights.end());
        while(mincap < maxcap){
            int mid = mincap + (maxcap - mincap)/2;
            int day = 0;
            int weight = 0;
            for(int i = 0; i < weights.size(); i++){
                weight += weights[i];
                if(weight > mid){
                    day++;
                    weight = weights[i];
                }
            }
            if(day < days) maxcap = mid;
            else mincap = mid + 1;
        }
        return mincap;
    }
};