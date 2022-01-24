#include <iostream>
#include <cstring>
using namespace std;

class CStudent
{
public:
	//CStudent(long a, string b, int c, int d, int e);//有参构造函数
	CStudent();//无参构造函数
	void SetData()
	{
		cout << "学号 " << "姓名" << "语文" << "数学" << "英语" << endl;
		cin >> No >> Name >> DegChinese >> DegMaths >> DegEnglish;
	};
	void Display()
	{
		cout << No << Name << DegChinese << DegMaths << DegEnglish << endl;
	}
	void Average()
	{

	}
private:
	long No;
	string Name;
	int DegChinese;
	int DegMaths;
	int DegEnglish;
};

/*CStudent::CStudent(long a, string b, int c, int d, int e)
{
	No = a; Name = b; DegChinese = c; DegMaths = d; DegEnglish = e;
}*/

CStudent::CStudent()
{
	No = 0; Name = "未知"; DegChinese = 0; DegMaths = 0; DegEnglish = 0;
}

int main()
{
	CStudent a;
	a.SetData();
	a.Display();
	return 0;
}