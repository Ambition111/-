/*
	���������ַ�����ʽ�ķǸ�����num1 ��num2���������ǵĺ͡�

	��ʾ��
	num1 ��num2 �ĳ��ȶ�С�� 5100
	num1 ��num2 ��ֻ��������0-9
	num1 ��num2 ���������κ�ǰ����
	�㲻��ʹ���κ΃Ƚ� BigInteger �⣬?Ҳ����ֱ�ӽ�������ַ���ת��Ϊ������ʽ
*/
class Solution {
public:
    int add(int a, int b, int &carry)
    {
        int sum = a + b + carry;
        if (sum >= 10)
        {
            sum = sum - 10;
            carry = 1;   //�����н�λ
        }
        else
            carry = 0;
        return sum;
    }
    string addStrings(string num1, string num2) {
        //�ȷ�ת���ַ��������ڴ����λ
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int i = 0, j = 0, carry = 0; //��λ
        int sum = 0;
        string res;

        while (i < num1.size() && j < num2.size())
        {
            sum = add(num1[i++] - '0', num2[j++] - '0', carry);
            res += sum + '0';
        }

        while (i < num1.size())
        {
            sum = add(num1[i++] - '0', 0 , carry);
            res += sum + '0';
        }

        while (j < num2.size())
        {
            sum = add(0, num2[j++] - '0', carry);
            res += sum + '0';
        }

        if (carry > 0)
            res += carry + '0';

        reverse(res.begin(), res.end());
        return res;
    }
};
