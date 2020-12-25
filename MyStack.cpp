//用两个队列实现栈
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        //将数据入到非空的那个队列中
        if (!q1.empty())
            q1.push(x);
        else
            q2.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int val;
        while (!q1.empty())
        {
            val = q1.front();
            q1.pop();
            if (q1.empty())
                return val;
            q2.push(val);
        }
        while (!q2.empty())
        {
            val = q2.front();
            q2.pop();
            if (q2.empty())
                break;
            q1.push(val);
        }
        return val;
    }
    
    /** Get the top element. */
    int top() {
        int val;
        while (!q1.empty())
        {
            val = q1.front();
            q1.pop();
            q2.push(val);
            if (q1.empty())
                return val; 
        }
        while (!q2.empty())
        {
            val = q2.front();
            q2.pop();
            q1.push(val);
            if (q2.empty())
                break; 
        }
        return val;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty() && q2.empty();
    }
private:
    queue<int> q1;
    queue<int> q2;
};
