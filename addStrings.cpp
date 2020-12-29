/*
	给定两个字符串形式的非负整数num1 和num2，计算它们的和。

	提示：
	num1 和num2 的长度都小于 5100
	num1 和num2 都只包含数字0-9
	num1 和num2 都不包含任何前导零
	你不能使用任何內建 BigInteger 库，?也不能直接将输入的字符串转换为整数形式
*/
class Solution {
public:
    int add(int a, int b, int &carry)
    {
        int sum = a + b + carry;
        if (sum >= 10)
        {
            sum = sum - 10;
            carry = 1;   //代表有进位
        }
        else
            carry = 0;
        return sum;
    }
    string addStrings(string num1, string num2) {
        //先反转两字符串，便于处理进位
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int i = 0, j = 0, carry = 0; //进位
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
