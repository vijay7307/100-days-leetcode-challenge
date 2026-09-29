class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;
        for(int i = 0; i < num.size(); i++){
            while(!st.empty() && k > 0 && st.top() > num[i] - '0'){
                st.pop();
                k--;
            }
            st.push(num[i] - '0');
        }

        while(k > 0){
            st.pop();
            k--;
        }

        if(st.empty())return "0";

        string res = "";

        while(!st.empty()){
            res += char(st.top() + '0');
            st.pop();
        }

        reverse(res.begin(), res.end());

         int i = 0;

        while(i < res.size() && res[i] == '0'){
            i++;
        }

        res = res.substr(i);

        return res.size() == 0 ? "0" : res;
    }
};