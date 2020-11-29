class Int;
//���������������
ostream& operator<<(ostream &out, const Int& i);//����
istream& operator>>(istream &in, Int& i);//����

class Int
{
	//������Ԫ������ʵ��
	friend ostream& operator<<(ostream &out, const Int& i);
	friend istream& operator>>(istream &in, Int& i);
public:
	Int(int i = 0) : m_i(i)  {}
	~Int()  {}
public:
	bool operator==(const Int& i)
	{
		return m_i == i.m_i;
	}
	bool operator!=(const Int& i)
	{
		//return m_i != i.m_i;
		return !(*this == i);
	}
public:
	Int operator+(const Int& i)
	{
		return Int(m_i + i.m_i);
	}
	Int operator-(const Int& i)
	{
		return Int(m_i - i.m_i);
	}
	Int operator*(const Int& i)
	{
		return Int(m_i * i.m_i);
	}
	Int operator/(const Int& i)
	{
		return Int(m_i / i.m_i);
	}
	Int operator%(const Int& i)
	{
		return Int(m_i % i.m_i);
	}

	Int& operator+=(const Int& i)	//����Ҫ�ı��Լ������Է��ض��������
	{
		m_i += i.m_i;
		return *this;
	}
	Int& operator-=(const Int& i)
	{
		m_i -= i.m_i;
		return *this;
	}
	Int& operator*=(const Int& i)
	{
		m_i *= i.m_i;
		return *this;
	}
	Int& operator/=(const Int& i)
	{
		m_i /= i.m_i;
		return *this;
	}
	Int& operator%=(const Int& i)
	{
		m_i %= i.m_i;
		return *this;
	}

	Int operator>>(int offset)
	{
		return Int(m_i >> offset);
	}
	Int operator<<(int offset)
	{
		return Int(m_i << offset);
	}
	Int& operator>>=(int offset)
	{
		m_i >>= offset;
		return *this;
	}
	Int& operator<<=(int offset)
	{
		m_i <<= offset;
		return *this;
	}

	Int operator++(int)		//�﷨�涨������int�͵Ĳ���������Ϊ��++
	{
		//Int tmp = *this;//��������
		//m_i++;
		//return tmp;
		//�Ժ�����ǰ++�Ͳ��ú�++��Ч�ʸߣ���++�ṹ����ʱ���󻨷�ʱ��

		Int tmp = *this;
		++* this;	//����operator++()������д�ĺô��� ����ֻ����һ�������������������ļӷ����������ط�ֻ���ڵ��������ѣ��������ǳ����ӣ����ʡʱ��
		return tmp;
	}
	Int& operator++()		//ǰ++,�����Լ���++��ֵ�ظı䣬���������÷���
	{
		m_i++;
		return *this;
	}
	Int operator--(int)
	{
		Int tmp = *this;
		m_i--;
		return tmp;
	}
	Int& operator--()
	{
		m_i--;
		return *this;
	}
private:
	int m_i;
};

ostream& operator<<(ostream &out, const Int& i)
{
	out << i.m_i;
	return out;
}
istream& operator>>(istream &in, Int& i)
{
	in >> i.m_i;
	return in;
}
