#include<cstring>
#include<cstdio>

class CMyString {
public:
	CMyString(char *pData = nullptr);
	CMyString(const CMyString& str);
	~CMyString();

	CMyString& operator = (const CMyString& str);

	void Print();
private:
	char* m_pData;
};

CMyString::CMyString(char *pData)
{
	//ȱʡ���
	if (pData == nullptr)
	{
		m_pData = new char[1];
		m_pData[0] = '\0';
	}
	else
	{
		int len = strlen(pData);
		m_pData = new char[len + 1];
		strcpy(m_pData, pData);
	}

}

CMyString::CMyString(const CMyString& str)
{
	int len = strlen(str.m_pData);
	m_pData = new char[len + 1];
	strcpy(m_pData, str.m_pData);
}

CMyString& CMyString::operator = (const CMyString& str)
{
	//�Ը�ֵ���
	if (this == &str)
		return *this;

	//��ֵ������֮ǰ����ֵ�����Ѿ�����
	delete[]m_pData;
	m_pData = nullptr;

	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);
	return *this;
}

CMyString::~CMyString()
{
	delete[]m_pData;
	m_pData = nullptr;
}

void CMyString::Print()
{
	printf("%s\n", m_pData);
}

void Test1()
{
	const char *test = "hello world";
	//char *p = test;
	CMyString str1(const_cast<char*>(test));
	CMyString str2;
	str2 = str1;

	printf("The expected result is:\t%s\n", test);
	printf("The actual result is:\t");
	str2.Print();
}

//��ֵ���Լ�
void Test2()
{
	const char *test = "hello world";
	CMyString str1(const_cast<char*>(test));
	str1 = str1;

	printf("The expected result is:\t%s\n", test);
	printf("The actual result is:\t");
	str1.Print();
}

//���ظ�ֵ
void Test3()
{
	const char *test = "hello world";
	CMyString str1(const_cast<char*>(test));
	CMyString str2;
	CMyString str3;

	str3 = str2 = str1;

	printf("The expected result is:\t%s\n", test);
	printf("The actual result is:\t");
	str2.Print();
	str3.Print();
}

int main()
{
	Test1();
	Test2();
	Test3();

	return 0;
}