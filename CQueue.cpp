/*
	用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead 
	分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead?操作返回 -1 )
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
