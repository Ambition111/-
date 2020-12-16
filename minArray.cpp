/*
	��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
	����һ����������������һ����ת�������ת�������СԪ�ء�
	���磬����[3,4,5,1,2] Ϊ [1,2,3,4,5] ��һ����ת�����������СֵΪ 1��

	ʾ�� 1��
	���룺[3,4,5,1,2]
	�����1
	
	ʾ�� 2��
	���룺[2,2,2,0,1]
	�����0
*/ 

int minArray(int* numbers, int numbersSize){
    int left = 0;
    int right = numbersSize - 1;

    //��ֹ��ת������������������һ����������Сֵ
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
