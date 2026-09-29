class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> result(n, 0);
        for(int i = (2 * n) - 1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] <= nums[i%n]){
                st.pop();
            }
            result[i%n] = !st.empty() ? nums[st.top()] : -1;
            st.push(i%n);
        }
        return result;
    }
};