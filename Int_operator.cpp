class Int;
//输入输出流的重载
ostream& operator<<(ostream &out, const Int& i);//声明
istream& operator>>(istream &in, Int& i);//声明

class Int
{
	//声明友元，类外实现
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

	Int& operator+=(const Int& i)	//对象要改变自己，所以返回对象的引用
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

	Int operator++(int)		//语法规定，给定int型的参数，重载为后++
	{
		//Int tmp = *this;//拷贝构造
		//m_i++;
		//return tmp;
		//以后能用前++就不用后++，效率高，后++会构造临时对象花费时间

		Int tmp = *this;
		++* this;	//调用operator++()；这样写的好处： 代码只会在一个函数里做真真正正的加法，而其他地方只是在调动它而已，如果对象非常复杂，会节省时间
		return tmp;
	}
	Int& operator++()		//前++,对象自己先++，值回改变，所以用引用返回
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
