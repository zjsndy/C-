#include <iostream>
#include "GreatInt.h"
#include "Isprime.h"
#include <string>
using namespace std;

int main()
{
	string first;
	string second;
	cout << "������������:" << endl;

	cout << "��һ����: ";
	cin >> first;
	cout << "�ڶ�����: ";
	cin >> second;
	GreatInt one(first);

	GreatInt two(second);

	cout << endl;
	cout << "��һ����+�ڶ�����=" ;
	cout << one + two << endl;

	cout << endl;
	cout << "��һ����-�ڶ�����=" ;
	cout << one - two << endl;

	int a;
	cout << endl;
	cout << "������һ���������Ľ׳�:";
	cin >> a;
	cout <<a<< "�Ľ׳�:" ;
	GreatInt three;
	cout << three.factorial(a)<<endl;
  
    
      LL n;
	  cout << "����һ�����ж��Ƿ�Ϊ����:";
      while (cin >> n)
      {
		  if (Miller_Rabin(n))
			  cout << "������" << endl;
		  else
			  cout << "��������" << endl;
       }

	  system("pause");
      return 0;
   
}