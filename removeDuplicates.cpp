/*
	����һ���������飬����Ҫ��ԭ��ɾ���ظ����ֵ�Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Σ������Ƴ���������³��ȡ�
	��Ҫʹ�ö��������ռ䣬������� ԭ�� �޸��������� ����ʹ�� O(1) ����ռ����������ɡ�
*/

//����һ�����õ�����
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1)   return nums.size();

        auto it = nums.begin();
        auto it1 = it;
        it1++;
        while (it != nums.end() && it1 != nums.end())
        {
            if (*it == *it1)
            {
                while (it1 != nums.end() && *it == *it1)
                    it1++;
                it = nums.erase(++it, it1);
                it1 = it + 1;
            }
            else
            {
                it++;
                it1++;
            }
        }
        return nums.size();
    }
};
//��������˫ָ�뷨
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1)   return nums.size();
        int i = 0; 
        for (auto j = 1; j < nums.size(); ++j)
        {
            if (nums[i] != nums[j])
                nums[++i] = nums[j];
        } 
        return i + 1;
    }
};
