/*
	���������ַ������� word1�� word2��������������ʾ���ַ�����ͬ������ true�����򣬷��� false ��
	�����ʾ���ַ������������е�����Ԫ�ذ�˳�������γɵ��ַ�����
*/ 
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1;
        string s2;
        for (const auto& e : word1)
            s1 += e;
        for (const auto& e : word2)
            s2 += e;
        return s1 == s2;
    }
};
