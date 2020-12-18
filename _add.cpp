class Solution {
public:
    int add(int a, int b) {
        if (a == 0)     return b;
        if (b == 0)     return a;
        if (a == 0 && b == 0)   return 0;

        int sum = 0;
        int carry = 0;
        while (b)
        {
            sum = a ^ b;
            carry = (unsigned int)(a & b) << 1;  //c++��֧�ָ�ֵ���ƣ���Ҫǿ��ת��Ϊ�޷�����
            a = sum;
            b = carry;
        }
        return a;
    }
};
