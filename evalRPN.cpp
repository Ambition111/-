/*
	���� �沨����ʾ��������ʽ��ֵ����Ч����������� +, -, *, / ��
	ÿ��������������������Ҳ��������һ���沨�����ʽ��
*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int len = tokens.size();
        stack<int> st;

        for (int i = 0; i < len; ++i)
        {
            if (!(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"))
            {
                st.push(atoi(tokens[i].c_str()));
            }
            else
            {
                int left_value, right_value;
                right_value = st.top();
                st.pop();
                left_value = st.top();
                st.pop();

                if (tokens[i] == "+")
                    st.push(left_value + right_value);
                else if (tokens[i] == "-")
                    st.push(left_value - right_value);
                else if (tokens[i] == "*")
                    st.push(left_value * right_value);
                else
                    st.push(left_value / right_value);
            }
        }
        return st.top();
    }
};
