
/*
	���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳��
	����ѹ��ջ���������־�����ȡ�
	���磬���� {1,2,3,4,5} ��ĳջ��ѹջ���У����� {4,5,3,2,1} �Ǹ�ѹջ���ж�Ӧ��һ���������У�
	�� {4,3,5,1,2} �Ͳ������Ǹ�ѹջ���еĵ������С�
*/
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i = 0, j = 0;
        while (j < popped.size())
        {
            while (st.empty() || st.top() != popped[j])
            {
                if (i < pushed.size())
                    st.push(pushed[i++]);
                else
                    return false;
            }

            st.pop();
            j++;
        }
        return true;
    }
};
