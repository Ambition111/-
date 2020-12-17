/*
	输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
	为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，则输出"student. a am I"
	
	示例 1：
	输入: "the sky is blue"
	输出:?"blue is sky the"
	
	示例 2：
	输入: " ?hello world! ?"
	输出:?"world! hello"
	解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
	
	示例 3：
	输入: "a good ? example"
	输出:?"example good a"
	解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
*/ 

class Solution {
public:
    string reverseWords(string s) {
        if (s.size() == 0)      return "";

        int i = 0, j = s.size() - 1;
        while (s[i] == ' ')     i++;    //去掉头部空格
        while (s[j] == ' ')     j--;    //去掉尾部空格
        if (i >= s.size() || j < 0)     return "";

        s = s.substr(i, j - i + 2);     //截取中间字符串
        i = j = s.size() - 1;
        string res("");                 //定义一个空串
        while (i >= 0)
        {
            while (i >= 0 && s[i] != ' ')     --i;      //从尾部第一个字符开始到遇到第一个空格
            res.append(' ' + s.substr(i + 1, j - i));   //将i到j之间的字符追加到res中
            while (i >= 0 && s[i] == ' ')     --i;      //继续跳过中间空格
            j = i;          //重新将i和j都指到新的第一个非空字符
        }
        i = 0;
        while (res[i] == ' ')     i++;  //去掉前面空格并截取
        return res.substr(i, res.size());
    }
};
