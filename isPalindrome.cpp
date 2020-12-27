/*
    ����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��
	˵���������У����ǽ����ַ�������Ϊ��Ч�Ļ��Ĵ���
	
	ʾ�� 1:
	����: "A man, a plan, a canal: Panama"
	���: true
	
	ʾ�� 2:
	����: "race a car"
	���: false
*/

class Solution {
public:
    bool isLetterOrDigit(char c)
    {
        return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z'));
    }
    bool isPalindrome(string s) {
        if (s.size() <= 1)      return true;

        for (int i = 0; i < s.size(); ++i) //Сдת��д
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] += 32;
        }

        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {
            while (left < right && !isLetterOrDigit(s[left]))
                left++; //�������ң��������ֻ���ĸ������
            while (left < right && !isLetterOrDigit(s[right]))
                right--; //�������󣬲������ֻ���ĸ������
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};
