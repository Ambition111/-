/*
	在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。

	示例1:
	s = "abaccdeff"
	返回 "b"
	
	示例2:
	s = "" 
	返回 " 
*/ 

class Solution {
public:
    char firstUniqChar(string s) 
    {
        int hash[256] = {0};   //统计相应字符出现的次数

        for (int i = 0; i < s.size(); ++i)
        {
            ++hash[s[i]];
        }
        for (int i = 0; i < s.size(); ++i)
        {
            if (hash[s[i]] == 1)
                return s[i];
        }
        return ' '; //如果没找到返回' '
    }
};
class Solution {
public:
    char firstUniqChar(string s) 
    {
        for (int i = 0; i < s.size(); ++i)
        {
            //同时正向查找和逆向查找，如果查找的字符下标相同说明这个字符只出现了一次
            int index = s.find(s[i]);
            int reverse_index = s.rfind(s[i]);
            if (index == reverse_index)
                return s[index];
        }
        return ' ';
	  }
