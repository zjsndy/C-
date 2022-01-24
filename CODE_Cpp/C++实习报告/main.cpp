#include <iostream>
#include "GreatInt.h"
#include "Isprime.h"
#include <string>
using namespace std;

int main()
{
	string first;
	string second;
	cout << "请输入两个数:" << endl;

	cout << "第一个数: ";
	cin >> first;
	cout << "第二个数: ";
	cin >> second;
	GreatInt one(first);

	GreatInt two(second);

	cout << endl;
	cout << "第一个数+第二个数=" ;
	cout << one + two << endl;

	cout << endl;
	cout << "第一个数-第二个数=" ;
	cout << one - two << endl;

	int a;
	cout << endl;
	cout << "请输入一个数求它的阶乘:";
	cin >> a;
	cout <<a<< "的阶乘:" ;
	GreatInt three;
	cout << three.factorial(a)<<endl;
  
    
      LL n;
	  cout << "请入一个数判断是否为素数:";
      while (cin >> n)
      {
		  if (Miller_Rabin(n))
			  cout << "是素数" << endl;
		  else
			  cout << "不是素数" << endl;
       }

	  system("pause");
      return 0;
   
}