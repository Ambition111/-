/*
	���ַ��� s ���ҳ���һ��ֻ����һ�ε��ַ������û�У�����һ�����ո� s ֻ����Сд��ĸ��

	ʾ��1:
	s = "abaccdeff"
	���� "b"
	
	ʾ��2:
	s = "" 
	���� " 
*/ 

class Solution {
public:
    char firstUniqChar(string s) 
    {
        int hash[256] = {0};   //ͳ����Ӧ�ַ����ֵĴ���

        for (int i = 0; i < s.size(); ++i)
        {
            ++hash[s[i]];
        }
        for (int i = 0; i < s.size(); ++i)
        {
            if (hash[s[i]] == 1)
                return s[i];
        }
        return ' '; //���û�ҵ�����' '
    }
};
class Solution {
public:
    char firstUniqChar(string s) 
    {
        for (int i = 0; i < s.size(); ++i)
        {
            //ͬʱ������Һ�������ң�������ҵ��ַ��±���ͬ˵������ַ�ֻ������һ��
            int index = s.find(s[i]);
            int reverse_index = s.rfind(s[i]);
            if (index == reverse_index)
                return s[index];
        }
        return ' ';
	  }
