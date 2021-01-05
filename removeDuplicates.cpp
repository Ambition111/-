/*
	给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
	不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
*/

//方法一：利用迭代器
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
//方法二：双指针法
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
