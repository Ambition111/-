class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if (min_st.empty() || x <= min_st.top())
            min_st.push(x);     //�����СջΪ�ջ���xС����Сջ��ջ��Ԫ�أ��ͽ�xѹ����Сջ
        st.push(x);   //����xΪ��ֵ�����Ὣ��ѹ����ͨջ��
    }
    
    void pop() {
        int val = st.top();
        st.pop();
        if (val == min_st.top())
            min_st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
private:
    stack<int> st;
    stack<int> min_st;
};
