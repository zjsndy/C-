#include <iostream>
#include <cstring>
using namespace std;

class Student
{
public:
	string s_name;
	string s_no;
	void show()
	{
		cout << "ѧ��������Ϊ:" << s_name <<endl<< "ѧ����ѧ��Ϊ:" << s_no << endl;
	};
};

int main()
{
	Student A;
	A.s_name = "�ܽ�";
	A.s_no = "200860228";
	A.show();
	system("pause");
	return 0;
}