//���ù�ʽa(i+1)=(a(i)+(n/a(i)))/2,��n��ƽ����,����ʼֵΪ1                    

float SquareRoot(unsigned int n)
{
	float oldRoot =  0;    /*  ��һ�εõ��ĸ�                 */
	float newRoot = 1;     /*  ���µõ��ĸ�                    */
/*  ����ֵ�Ĳ��Ѿ���             */
	while((oldRoot-newRoot>0.0000001) ||
		     (oldRoot-newRoot)<-0.00000001)/*  float��������Ϊ���ѵõ�   */
	{
		oldRoot = newRoot;
		newRoot = (newRoot + n/newRoot)/2;
	}

	return newRoot;
}
