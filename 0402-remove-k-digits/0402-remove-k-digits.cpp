class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(int i = 0; i < num.size(); i++){
            while(!st.empty() && k > 0 && st.top() > num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while(k > 0){
            st.pop();
            k--;
        }

        //building result

        string result = "";

        while(!st.empty()){
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());

        // remove leading zeros

        int i = 0;

        while(i < result.size() && result[i] == '0') i++;

        result = result.substr(i);

        if(result.size() == 0) return "0";

        return result;
        
    }
};