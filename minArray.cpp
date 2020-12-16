/*
	把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
	输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
	例如，数组[3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为 1。

	示例 1：
	输入：[3,4,5,1,2]
	输出：1
	
	示例 2：
	输入：[2,2,2,0,1]
	输出：0
*/ 

int minArray(int* numbers, int numbersSize){
    int left = 0;
    int right = numbersSize - 1;

    //防止旋转后的数组依旧有序。则第一个数就是最小值
    int mid = left;
    while (numbers[left] > numbers[right])
    {
        mid = (left + right)/2;
        if (numbers[mid] >= numbers[left])
            left = mid;
        else if (numbers[mid] <= numbers[right])
            right = mid;

        if (left + 1 == right)
        {
            mid = right;
            break;
        }    
    }    

    if (numbers[left] == numbers[right] && numbers[right] == numbers[mid])
    {
        int min = numbers[left];
        for (int i = left + 1; i < right; ++i)
        {
            if (numbers[i] <= min)
            {
                min = numbers[i];
            }
        }
        return min;
    }
    return numbers[mid];
}
