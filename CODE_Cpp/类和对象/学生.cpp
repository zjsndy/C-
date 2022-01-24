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
		cout << "学生的姓名为:" << s_name <<endl<< "学生的学号为:" << s_no << endl;
	};
};

int main()
{
	Student A;
	A.s_name = "周杰";
	A.s_no = "200860228";
	A.show();
	system("pause");
	return 0;
}