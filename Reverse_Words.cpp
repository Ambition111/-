/*
	����һ��Ӣ�ľ��ӣ���ת�����е��ʵ�˳�򣬵��������ַ���˳�򲻱䡣
	Ϊ������������ź���ͨ��ĸһ���������������ַ���"I am a student. "�������"student. a am I"
	
	ʾ�� 1��
	����: "the sky is blue"
	���:?"blue is sky the"
	
	ʾ�� 2��
	����: " ?hello world! ?"
	���:?"world! hello"
	����: �����ַ���������ǰ����ߺ����������Ŀո񣬵��Ƿ�ת����ַ����ܰ�����
	
	ʾ�� 3��
	����: "a good ? example"
	���:?"example good a"
	����: ����������ʼ��ж���Ŀո񣬽���ת�󵥴ʼ�Ŀո���ٵ�ֻ��һ����
*/ 

class Solution {
public:
    string reverseWords(string s) {
        if (s.size() == 0)      return "";

        int i = 0, j = s.size() - 1;
        while (s[i] == ' ')     i++;    //ȥ��ͷ���ո�
        while (s[j] == ' ')     j--;    //ȥ��β���ո�
        if (i >= s.size() || j < 0)     return "";

        s = s.substr(i, j - i + 2);     //��ȡ�м��ַ���
        i = j = s.size() - 1;
        string res("");                 //����һ���մ�
        while (i >= 0)
        {
            while (i >= 0 && s[i] != ' ')     --i;      //��β����һ���ַ���ʼ��������һ���ո�
            res.append(' ' + s.substr(i + 1, j - i));   //��i��j֮����ַ�׷�ӵ�res��
            while (i >= 0 && s[i] == ' ')     --i;      //���������м�ո�
            j = i;          //���½�i��j��ָ���µĵ�һ���ǿ��ַ�
        }
        i = 0;
        while (res[i] == ' ')     i++;  //ȥ��ǰ��ո񲢽�ȡ
        return res.substr(i, res.size());
    }
};
