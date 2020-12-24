/*
	������ջʵ��һ�����С����е��������£���ʵ�������������� appendTail �� deleteHead 
	�ֱ�����ڶ���β�������������ڶ���ͷ��ɾ�������Ĺ��ܡ�(��������û��Ԫ�أ�deleteHead?�������� -1 )
*/
class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        in_st.push(value);
    }
    
    int deleteHead() {
        if (out_st.empty())
        {
            if (in_st.empty())
                return -1;
            while (!in_st.empty())
            {
                out_st.push(in_st.top());
                in_st.pop();
            }
        }
        int val = out_st.top();
        out_st.pop();
        return val;
    }
private:
    stack<int> in_st;
    stack<int> out_st;
};
