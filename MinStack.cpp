class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if (min_st.empty() || x <= min_st.top())
            min_st.push(x);     //如果最小栈为空或者x小于最小栈的栈顶元素，就将x压入最小栈
        st.push(x);   //不管x为何值，都会将它压入普通栈中
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
