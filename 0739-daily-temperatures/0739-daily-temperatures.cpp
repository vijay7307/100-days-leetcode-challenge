class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result;
        stack<int> st;
        for(int i = temperatures.size() - 1; i >= 0; i--){
            //check for top element is greater?
            while(!st.empty()){
                if(temperatures[st.top()] > temperatures[i]) {
                    result.push_back(st.top() - i);
                    break;
                }
                else {
                    st.pop();
                }
            }
            if(st.empty()) result.push_back(0);
            st.push(i);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};