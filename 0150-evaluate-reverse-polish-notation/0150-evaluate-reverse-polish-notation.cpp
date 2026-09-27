class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string x : tokens){
            if(x == "+" || x == "-" || x == "*" || x == "/"){
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                int res = 0;
                if(x == "+") res = op1 + op2;
                else if(x == "-") res = op2 - op1;
                else if(x == "*") res = op2 * op1;
                else res = op2 / op1;
                st.push(res);
                continue;
            }
            st.push(stoi(x));
        }
        return st.top();
    }
};