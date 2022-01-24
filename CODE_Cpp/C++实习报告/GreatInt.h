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
	GreatInt(string nums = "");	    //���ַ������й��죬Ĭ�Ϲ��캯��		
	GreatInt(const GreatInt& a);    //�������캯��
	~GreatInt();
	friend ostream& operator<<(ostream& os, const GreatInt& rhs);
	GreatInt operator+(const GreatInt& rhs) const;		//�ӷ�����
	GreatInt operator-(const GreatInt& rhs) const;		//��������
	const GreatInt& factorial(int nums);				//�׳�����
private:
	int compare(const GreatInt& rhs) const;			//���бȽ�
	string add(const GreatInt& lhs, const GreatInt& rhs) const;			
	string min(const GreatInt& lhs, const GreatInt& rhs) const;
	void multiply(const int n);						//�����׳�����	
	bool signal;
	Queue head;
	Queue tail;
};

#endif
