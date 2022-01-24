#pragma once
#ifndef GREATINT
#define GREATINT
#include <string>

using namespace std;

typedef struct queue {
	int i;
	queue* next;
}*Queue;

class GreatInt {
public:
	GreatInt(string nums = "");	    //用字符串进行构造，默认构造函数		
	GreatInt(const GreatInt& a);    //拷贝构造函数
	~GreatInt();
	friend ostream& operator<<(ostream& os, const GreatInt& rhs);
	GreatInt operator+(const GreatInt& rhs) const;		//加法运算
	GreatInt operator-(const GreatInt& rhs) const;		//减法运算
	const GreatInt& factorial(int nums);				//阶乘运算
private:
	int compare(const GreatInt& rhs) const;			//进行比较
	string add(const GreatInt& lhs, const GreatInt& rhs) const;			
	string min(const GreatInt& lhs, const GreatInt& rhs) const;
	void multiply(const int n);						//辅助阶乘运算	
	bool signal;
	Queue head;
	Queue tail;
};

#endif
