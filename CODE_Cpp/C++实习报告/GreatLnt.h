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
	GreatInt(string nums = "");
	GreatInt(const GreatInt& a);
	GreatInt();
	friend ostream& operator<<(ostream& os, const GreatInt& rhs);
	GreatInt operator+(const GreatInt& rhs)const;
	GreatInt operator-(const GreatInt& rhs)const;
	const GreatInt& factorial(int nums);
private:
	int compare(const GreatInt& rhs) const;
	string add(const GreatInt& lhs, const GreatInt& rhs)const;
	string min(const GreatInt& lhs, const GreatInt& rhs)const;
	void multiply(const int n);
	bool signal;
	Queue head;
	Queue tail;
};
#endif // !GREATINT
