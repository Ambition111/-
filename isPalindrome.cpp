/*
    给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
	说明：本题中，我们将空字符串定义为有效的回文串。
	
	示例 1:
	输入: "A man, a plan, a canal: Panama"
	输出: true
	
	示例 2:
	输入: "race a car"
	输出: false
*/

class Solution {
public:
    bool isLetterOrDigit(char c)
    {
        return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z'));
    }
    bool isPalindrome(string s) {
        if (s.size() <= 1)      return true;

        for (int i = 0; i < s.size(); ++i) //小写转大写
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] += 32;
        }

        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {
            while (left < right && !isLetterOrDigit(s[left]))
                left++; //从左往右，不是数字或字母则跳过
            while (left < right && !isLetterOrDigit(s[right]))
                right--; //从右往左，不是数字或字母则跳过
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};
