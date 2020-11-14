//利用公式a(i+1)=(a(i)+(n/a(i)))/2,求n的平方根,根初始值为1                    

float SquareRoot(unsigned int n)
{
	float oldRoot =  0;    /*  上一次得到的根                 */
	float newRoot = 1;     /*  最新得到的根                    */
/*  两次值的差已经在             */
	while((oldRoot-newRoot>0.0000001) ||
		     (oldRoot-newRoot)<-0.00000001)/*  float精度内认为根已得到   */
	{
		oldRoot = newRoot;
		newRoot = (newRoot + n/newRoot)/2;
	}

	return newRoot;
}
