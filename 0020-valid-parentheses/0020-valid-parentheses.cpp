class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto x : s){
            if(x == '(' || x == '{' || x == '['){
                st.push(x);
            }
            else if(x == ')' || x == '}' || x == ']'){
                if(st.empty()) return false;
                char top = st.top();
                if((top == '(' && x != ')') || (top == '{' && x != '}') || (top == '[' && x != ']'))return false;
                else st.pop();
            }
        }

        return !st.empty() ? false : true;
    }
};