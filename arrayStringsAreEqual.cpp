/*
	给你两个字符串数组 word1和 word2。如果两个数组表示的字符串相同，返回 true，否则，返回 false 。
	数组表示的字符串是由数组中的所有元素按顺序连接形成的字符串。
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
