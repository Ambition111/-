class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        if (min_st.empty() || x <= min_st.top())
            min_st.push(x);
        st.push(x);
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
    
    int min() {
        return min_st.top();
    }
private:
    stack<int> st;
    stack<int> min_st;
};
