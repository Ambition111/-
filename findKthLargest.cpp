/*
	��δ������������ҵ��� k ������Ԫ�ء�
	��ע�⣬����Ҫ�ҵ������������ĵ� k ������Ԫ�أ������ǵ� k ����ͬ��Ԫ��
	ʾ�� 1:
	����: [3,2,1,5,6,4] �� k = 2
	���: 5
	
	ʾ�� 2:
	����: [3,2,3,1,2,4,5,5,6] �� k = 4
	���: 4
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq; //���ȼ�����
        for (const auto &e : nums)
        {
            pq.push(e); //�γ�һ�����
        }
        for (int i = 0; i < k - 1; ++i)
        {
            pq.pop();
        }
        return pq.top();
    }
};
